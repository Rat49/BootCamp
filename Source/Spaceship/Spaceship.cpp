#include "Spaceship.h"

Spaceship::Spaceship(const sf::Vector2f& position,const sf::Vector2f& speed, InputManager & input,
	ImageSequenceResource &spaceshipAnimationImseq, ImageSequenceResource& spaceshipFlickeringImseq)
	: RigidBody(position, speed, spaceshipAnimationImseq.GetWidth() / 2.0f, 1.0f)
	, _liveCount(3)
	, _isDamaged(false)
	, _initialDirection(sf::Vector2f(0.0f, -1.0f))
	, _spaceshipDirection(_initialDirection)
	, _spaceshipAnimationImseq(spaceshipAnimationImseq)
	, _spaceshipFlickeringImseq(spaceshipFlickeringImseq)
	, _rotationAngle(17.0f)
	, _acceleration(15.0f)
	, _maxSquareSpeed(12000.0f)
	, _flickeringTime(sf::seconds(1.0f))
	, _timeAfterDamage(sf::seconds(0.0f))
	, _input(input)	
	, _inputTime(sf::milliseconds(100))
	, _inputAccumulatedTime(sf::milliseconds(0))
	, _rechargeRocketTime(sf::seconds(3.0f))
	, _rechargeBulletTime(sf::seconds(0.15f))
	, _bulletRebound(5.0f)
	, _rocketRebound(15.0f)
{
	_zOrder = 1;
	_speedDirection = GetNormalizedVelocity(GetSpeed());
	_spaceshipSprite = new sf::Sprite();
	_spaceshipAnimation = new AnimationPlayer(*_spaceshipSprite, spaceshipAnimationImseq, true);
	_spaceshipFlickering = new AnimationPlayer(*_spaceshipSprite, spaceshipFlickeringImseq, true);
	_spaceshipSprite->setPosition(position);
	_spaceshipSprite->setOrigin(_spaceshipAnimation->GetWidth() / 2, _spaceshipAnimation->GetHeight() / 2);
	_spaceshipAnimation->Start();

	Dispatcher& dispatcher = Dispatcher::getInstance();
	_tokenForCollisionEventBetweenAsteroidAndSpaceship = dispatcher.Connect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID,
		[&](const Event& event)
	{
		const CollisionEventBetweenAsteroidAndSpaceship& currentEvent = static_cast<const CollisionEventBetweenAsteroidAndSpaceship&>(event);
		//currentEvent._spaceship minus life
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
	if (_timeAfterPowerfulShot.asSeconds() < _rechargeRocketTime.asSeconds())
	{
		return;
	}

	CreateRocketEvent createRocket(_spaceshipSprite->getPosition(), _spaceshipDirection);
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Send(createRocket, EventTypes::createRocketEventID);
	
	_timeAfterPowerfulShot = sf::seconds(0.0f); 
	GainRebound(_rocketRebound);
}


void Spaceship::OrdinaryShoot()
{
	if (_timeAfterBulletShot.asSeconds() < _rechargeBulletTime.asSeconds())
	{
		return;
	}
	
	CreateBulletEvent createBullet(_spaceshipSprite->getPosition(),_spaceshipDirection);
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Send(createBullet, EventTypes::createBulletEventID);

	_timeAfterBulletShot = sf::seconds(0.0f);
	GainRebound(_bulletRebound);
}

void Spaceship::RotateSpaceship(float degreeAngle)
{
	_spaceshipDirection = RotateVector(_spaceshipDirection, degreeAngle);
	_spaceshipSprite->setRotation(_spaceshipSprite->getRotation() + degreeAngle);
}

void Spaceship::ControlSpeed(float deltaSpeed)
{
	float speedValue = std::sqrt(GetSquareLength(GetSpeed()));

	if (!((_speedDirection == _spaceshipDirection) || (_speedDirection == -_spaceshipDirection)))
	{
		_speedDirection = deltaSpeed > 0 ? _spaceshipDirection : -_spaceshipDirection;

		SetSpeed(_speedDirection * speedValue);
	}

	sf::Vector2f newSpeed = GetSpeed() + deltaSpeed * _spaceshipDirection;

	if (GetSquareLength(newSpeed) < _maxSquareSpeed)
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

	_timeAfterDamage = sf::seconds(0.0f);
	_isDamaged = true;
}

void Spaceship::SetNormalMode()
{
	_spaceshipFlickering->Stop();
	_spaceshipAnimation->Start();

	_isDamaged = false;
}



void Spaceship::Update(const sf::Time& deltaTime)
{
	//============temporary===============
	enum class GameActions {
		MoveUp,
		MoveDown,
		MoveLeft,
		MoveRight,
		Exit,
		Choose,
		Shoot,
		SuperShoot
	};
	//====================================

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
			_inputAccumulatedTime = sf::milliseconds(0);
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
			_inputAccumulatedTime = sf::milliseconds(0);
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
			_inputAccumulatedTime = sf::milliseconds(0);
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
			_inputAccumulatedTime = sf::milliseconds(0);
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::SuperShoot), stateSuperShoot) && stateSuperShoot == ButtonsState::JustPressed)
	{
		PowerfulShoot();
	}
	if (_input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && stateShoot == ButtonsState::JustPressed)
	{
		OrdinaryShoot();
	}
	//==========================only for test============================================
	if (_input.GetState(static_cast<int>(GameActions::Choose), stateShoot) && stateShoot == ButtonsState::JustPressed)
	{
		SetFlickeringMode();
	}
	//===================================================================================

	_timeAfterPowerfulShot += deltaTime;
	_timeAfterBulletShot += deltaTime;
	RigidBody::Update(deltaTime.asSeconds());
	_spaceshipSprite->setPosition(RigidBody::GetCoordinates());
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
	DrawableManager::getInstance()._drawableObjects.push_back(this);
	DrawableManager::getInstance().SortDrawableVector();
}

int Spaceship::GetZOrder() const
{
	return _zOrder;
}

void Spaceship::Draw(sf::RenderWindow& window)
{
	window.draw(*(_spaceshipAnimation->GetSprite()));
}

Spaceship::~Spaceship()
{
	Dispatcher& dispatcher = Dispatcher::getInstance();
	dispatcher.Disconnect(EventTypes::collisionEventBetweenAsteroidAndSpaceshipID , _tokenForCollisionEventBetweenAsteroidAndSpaceship);
}