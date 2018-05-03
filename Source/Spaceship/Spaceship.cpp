#include "Spaceship.h"

Spaceship::Spaceship(const std::multimap<const std::string, const std::string>& spaceshipConfig, InputManager& input, ImageSequenceResource& spaceshipAnimationImseq,
	ImageSequenceResource& spaceshipFlickeringImseq, ResourceManager &rm)
	: RigidBody({ 0, 0 }, {0, 0}, spaceshipAnimationImseq.GetWidth() / 2.5f, 1.0f)

	, _isDamaged(false)
	, _initialDirection(sf::Vector2f(0.0f, -1.0f))
	, _spaceshipDirection(_initialDirection)
	, _spaceshipAnimationImseq(spaceshipAnimationImseq)
	, _spaceshipFlickeringImseq(spaceshipFlickeringImseq)
	, _rotationAngle(5.0f)
	, _acceleration(25.0f)
	, _maxSquareSpeed(50000.0f)
	, _flickeringTime(sf::seconds(1.0f))
	, _timeAfterDamage(sf::seconds(0.0f))
	, _input(input)	
	, _inputTime(sf::milliseconds(10))
	, _inputAccumulatedTime(sf::milliseconds(0))
	, _rechargeRocketTime(sf::seconds(0.5f))
	, _rechargeBulletTime(sf::seconds(0.2f))
	, _bulletRebound(5.0f)
	, _rocketRebound(15.0f)
	, _shotIndentValue(50.0f)
	, _maxLifeCount(3)
	, _bulletSound(rm.GetResource<AudioResource>("shootSound"))
	, _rocketSound(rm.GetResource<AudioResource>("rocketSound"))
	, _collisionSound(rm.GetResource<AudioResource>("collisionSound"))
	
{
	spaceshipConfig;
	float positionX = atof(spaceshipConfig.find("PositionX")->second.c_str());
	float positionY = atof(spaceshipConfig.find("PositionY")->second.c_str());
	float speedX = atof(spaceshipConfig.find("SpeedX")->second.c_str());
	float speedY = atof(spaceshipConfig.find("SpeedY")->second.c_str());
	RigidBody::SetCoordinates({ positionX, positionY});
	RigidBody::SetSpeed({ speedX, speedY});
	_liveCount = atoi(spaceshipConfig.find("LifeCount")->second.c_str());	
	_HP = atoi(spaceshipConfig.find("HP")->second.c_str());
	_damage = atoi(spaceshipConfig.find("Damage")->second.c_str());
	_zOrder = 1;
	_spaceshipSprite = new sf::Sprite();
	_speedDirection = GetNormalizedVelocity(GetSpeed());
	_spaceshipAnimation = new AnimationPlayer(_spaceshipSprite, &spaceshipAnimationImseq, true);
	_spaceshipFlickering = new AnimationPlayer(_spaceshipSprite, &spaceshipFlickeringImseq, true);
	_spaceshipSprite->setPosition({positionX, positionY});
	_spaceshipSprite->setOrigin(_spaceshipAnimation->GetWidth() / 2, _spaceshipAnimation->GetHeight() / 2);
	_spaceshipAnimation->Start();

	Dispatcher& dispatcher = Dispatcher::getInstance();
	_tokenForCollisionEventBetweenAsteroidAndSpaceship = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID,
		[&](const Event& event)
		{			
			const CollisionEventBetweenAsteroidAndSpaceship& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndSpaceship&>(event);
			SetFlickeringMode();
			if (_HP <= 0)
			{
				--_liveCount;
				if (_liveCount == 0)
				{
					std::cout << "Game Over" << std::endl;
					GameOverEvent gameOverEvent;
					dispatcher.Send(gameOverEvent, EventTypes::gameOverEventID);
					return;
				}
				else
				{
					SpaceshipRespawnEvent spaceshipRespawnEvent;
					dispatcher.Send(spaceshipRespawnEvent, EventTypes::spaceshipRespawnEventID);
					_HP = 100;
				}
			}
			else
			{
				if (!_isDamaged)
				{
					_HP -= _damage;
					_isDamaged = true;
				}
			}
			_collisionSound->Get().play();
			UpdateSpaceshipStateEvent updateSpaceshipStateEvent(_HP, _liveCount,_maxLifeCount);
			dispatcher.Send(updateSpaceshipStateEvent, EventTypes::updateSpaceshipStateEvent);
		});

	_tokenForCollisionEventBetweenAmmunitionAndSpaceship = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAmmunitionAndSpaceshipId,
		[&](const Event& event)
	{
		OnAmmunitionCollisionHandler(event);
	});
}

void Spaceship::Accelerate()
{
	ControlSpeed(_acceleration);
}

void Spaceship::Decelerate()
{
	ControlSpeed(-_acceleration);
}

void Spaceship::PowerfulShoot()
{
	if (_timeAfterPowerfulShot.asSeconds() < _rechargeRocketTime.asSeconds() || _rocketCount <= 0)
	{
		return;
	}
	--_rocketCount;
	_rocketSound->Get().play();

	UpdateSpaceshipWeaponStorageEvent updateSpaceshipStorageEvent(_bulletCount, _rocketCount);
	Dispatcher::getInstance().Send(updateSpaceshipStorageEvent, EventTypes::updateSpaceshipWeaponStorageEvent);

	sf::Vector2f indent = _spaceshipDirection * (GetRadius() + _shotIndentValue);

	CreateRocketEvent createRocket(_spaceshipSprite->getPosition() + indent, _spaceshipDirection, RigidBody::IsColliderVisible());
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Send(createRocket, EventTypes::createRocketEventID);
	
	_timeAfterPowerfulShot = sf::Time::Zero; 
	GainRebound(_rocketRebound);
}


void Spaceship::OrdinaryShoot()
{
	if (_timeAfterBulletShot.asSeconds() < _rechargeBulletTime.asSeconds() || _bulletCount <= 0)
	{
		return;
	}	
	_bulletCount -= 3;
	_bulletSound->Get().play();

	UpdateSpaceshipWeaponStorageEvent updateSpaceshipStorageEvent(_bulletCount, _rocketCount);
	Dispatcher::getInstance().Send(updateSpaceshipStorageEvent, EventTypes::updateSpaceshipWeaponStorageEvent);

	sf::Vector2f indent = _spaceshipDirection * (GetRadius() + _shotIndentValue);

	CreateBulletEvent createBullet(_spaceshipSprite->getPosition() + indent, _spaceshipDirection, RigidBody::IsColliderVisible());
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Send(createBullet, EventTypes::createBulletEventID);

	_timeAfterBulletShot = sf::Time::Zero;
	GainRebound(_bulletRebound);
}

void Spaceship::RotateSpaceship(float degreeAngle)
{
	_spaceshipDirection = RotateVector(_spaceshipDirection, degreeAngle);
	_spaceshipSprite->setRotation(_spaceshipSprite->getRotation() + degreeAngle);
}

void Spaceship::ControlSpeed(float deltaSpeed)
{
	float speedValue = std::sqrt(GetSquaredLength(GetSpeed()));

	if (!((_speedDirection == _spaceshipDirection) || (_speedDirection == -_spaceshipDirection)))
	{
		_speedDirection = deltaSpeed > 0 ? _spaceshipDirection : -_spaceshipDirection;

		SetSpeed(_speedDirection * speedValue);
	}

	sf::Vector2f newSpeed = GetSpeed() + deltaSpeed * _spaceshipDirection;

	if (GetSquaredLength(newSpeed) < _maxSquareSpeed)
	{
		SetSpeed(newSpeed);
	}
}

void Spaceship::GainRebound(float reboundValue)
{
	SetSpeed(GetSpeed() + -_spaceshipDirection * reboundValue);
	_speedDirection = GetNormalizedVelocity(GetSpeed());
}

void Spaceship::SetFlickeringMode()
{
	_spaceshipAnimation->Stop();
	_spaceshipFlickering->Start();

	_timeAfterDamage = sf::Time::Zero;
	//_isDamaged = true;
}

void Spaceship::SetNormalMode()
{
	_spaceshipFlickering->Stop();
	_spaceshipAnimation->Start();

	_isDamaged = false;
}


void Spaceship::OnAmmunitionCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAmmunitionAndSpaceship &collisionEvent = dynamic_cast<const CollisionEventBetweenAmmunitionAndSpaceship&>(cEvent);
	Ammunition* ammunition = collisionEvent.ammunition;
	Spaceship* spaceship = collisionEvent.spaceship;
	switch (ammunition->_ammunitionType)
	{
		case AmmunitionType::Bullet:
			_bulletCount = std::min(_maxBulletCount, static_cast<int>(_bulletCount + ammunition->capacity));
			break;
		case AmmunitionType::Rocket:
			_rocketCount = std::min(_maxRocketCount, static_cast<int>(_rocketCount + ammunition->capacity));
			break;
		case AmmunitionType::Aid:
			_HP = std::min(_maxHP, static_cast<int>(_HP + ammunition->capacity));
			UpdateSpaceshipStateEvent updateSpaceshipStateEvent(_HP, _liveCount, _maxLifeCount);
			Dispatcher::getInstance().Send(updateSpaceshipStateEvent, EventTypes::updateSpaceshipStateEvent);
			break;
		
	}

	UpdateSpaceshipWeaponStorageEvent updateSpaceshipStorageEvent(_bulletCount, _rocketCount);
	Dispatcher::getInstance().Send(updateSpaceshipStorageEvent, EventTypes::updateSpaceshipWeaponStorageEvent);
}

void Spaceship::Update(const sf::Time& deltaTime)
{

	ButtonsState stateMoveLeft;
	ButtonsState stateMoveRight;
	ButtonsState stateMoveUp;
	ButtonsState stateMoveDown;
	ButtonsState stateShoot;
	ButtonsState stateSuperShoot;

	_input.Update();
	if (_input.GetState(static_cast<int>(GameActions::MoveLeft), stateMoveLeft) && (stateMoveLeft == ButtonsState::JustPressed || stateMoveLeft == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else 
		{
			RotateSpaceship(-_rotationAngle);
			_inputAccumulatedTime = sf::Time::Zero;
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveRight), stateMoveRight) && (stateMoveRight == ButtonsState::JustPressed || stateMoveRight == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else
		{
			RotateSpaceship(_rotationAngle);
			_inputAccumulatedTime = sf::Time::Zero;
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveUp), stateMoveUp) && (stateMoveUp == ButtonsState::JustPressed || stateMoveUp == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else
		{
			Accelerate();
			_inputAccumulatedTime = sf::Time::Zero;
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveDown), stateMoveDown) && (stateMoveDown == ButtonsState::JustPressed || stateMoveDown == ButtonsState::Pressed))
	{
		if (_inputAccumulatedTime < _inputTime)
		{
			_inputAccumulatedTime += deltaTime;
		}
		else
		{
			Decelerate();
			_inputAccumulatedTime = sf::Time::Zero;
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::SuperShoot), stateSuperShoot) && (stateSuperShoot == ButtonsState::JustPressed || stateSuperShoot == ButtonsState::Pressed))
	{
			PowerfulShoot();
	
	}
	if (_input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && (stateShoot == ButtonsState::JustPressed || stateShoot == ButtonsState::Pressed))
	{
			OrdinaryShoot();
	}
	
	_timeAfterPowerfulShot += deltaTime;
	_timeAfterBulletShot += deltaTime;
	RigidBody::Update(deltaTime.asSeconds());

	if(GetX() > WindowResolution::_W)
	{
		SetX(0);
	}
	if(GetX() < 0)
	{
		SetX(WindowResolution::_W);
	}
	if(GetY() > WindowResolution::_H)
	{
		SetY(0);
	}
	if(GetY() < 0)
	{
		SetY(WindowResolution::_H);
	}

	sf::Vector2f rigidCoordinates = RigidBody::GetCoordinates();
	_spaceshipSprite->setPosition(rigidCoordinates.x + _spaceshipSprite->getLocalBounds().width / coefficientOfAnimation, rigidCoordinates.y + _spaceshipSprite->getLocalBounds().height / coefficientOfAnimation);
	_spaceshipAnimation->Update(deltaTime);
	_spaceshipFlickering->Update(deltaTime);

	if (_isDamaged)
	{
		if (_timeAfterDamage < _flickeringTime)
		{
			_timeAfterDamage += deltaTime;
		}
		else
		{
			SetNormalMode();
		}
	}

}

void Spaceship::AddToDrawableManager()
{
	DrawableManager::getInstance().AddDrawableObject(this);
}

int Spaceship::GetZOrder() const
{
	return _zOrder;
}

void Spaceship::Draw(sf::RenderWindow& window)
{
	window.draw(*(_spaceshipAnimation->GetSprite()));
	if (IsColliderVisible())
	{
		sf::CircleShape physicsShape(GetRadius());
		physicsShape.setPosition(GetCoordinates());
		physicsShape.setOutlineColor(sf::Color(255, 255, 255, 255));
		physicsShape.setFillColor(sf::Color::Transparent);
		physicsShape.setOutlineThickness(1);

		window.draw(physicsShape);
		sf::CircleShape circleCenter(1);
		circleCenter.setPosition(GetX() + GetRadius(),
			GetY() + GetRadius());
		circleCenter.setRadius(1.f);
		circleCenter.setFillColor(sf::Color::Green);
		window.draw(circleCenter);
	}
	
}

void Spaceship::SetDamage(unsigned int damage)
{
	_damage = damage;
}

void Spaceship::Reset(const std::multimap<const std::string, const std::string>& spaceshipConfig)
{

	float positionX = atof(spaceshipConfig.find("PositionX")->second.c_str());
	float positionY = atof(spaceshipConfig.find("PositionY")->second.c_str());
	float speedX = atof(spaceshipConfig.find("SpeedX")->second.c_str());
	float speedY = atof(spaceshipConfig.find("SpeedY")->second.c_str());
	RigidBody::SetCoordinates({ positionX, positionY });
	RigidBody::SetSpeed({ speedX, speedY });
	_liveCount = atoi(spaceshipConfig.find("LifeCount")->second.c_str());
	_HP = atoi(spaceshipConfig.find("HP")->second.c_str());
	_damage = atoi(spaceshipConfig.find("Damage")->second.c_str());
	_spaceshipDirection = _initialDirection;
	_speedDirection = GetNormalizedVelocity(GetSpeed());
	_spaceshipSprite->setPosition({ positionX, positionY });
	_spaceshipSprite->setRotation(0.0f);
	_spaceshipAnimation->Reset();
	_rocketCount = 90;
	_bulletCount = 10;

	Dispatcher& dispatcher = Dispatcher::getInstance();
	UpdateSpaceshipStateEvent updateSpaceshipStateEvent(_HP, _liveCount, _maxLifeCount);
	dispatcher.Send(updateSpaceshipStateEvent, EventTypes::updateSpaceshipStateEvent);

	UpdateSpaceshipWeaponStorageEvent updateSpaceshipWeaponStorageEvent(_bulletCount, _rocketCount);
	dispatcher.Send(updateSpaceshipWeaponStorageEvent, EventTypes:::updateSpaceshipWeaponStorageEvent);
}

Spaceship::~Spaceship()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID , _tokenForCollisionEventBetweenAsteroidAndSpaceship);
}