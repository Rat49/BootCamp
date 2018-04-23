#include "Spaceship.h"

const float PI_F = 3.14159265358979f;

Spaceship::Spaceship(sf::Vector2f position, sf::Vector2f speed, InputManager & input,
	ImageSequenceResource &spaceshipAnimationImseq, TextureResource &ordinaryShotTexture, TextureResource &powerfulShotTexture)
	: RigidBody(position, speed, spaceshipAnimationImseq.GetWidth() / 2.0f, 1.0f)
	, _initialDirection(sf::Vector2f(0.0f, -1.0f))
	, _spaceshipDirection(_initialDirection)
	, _input(input)
	, _isRecharged(true)
	, _rotationAngle(17.0f)
	, _currentAngle(0.0f)
	, _inputTime(sf::milliseconds(100))
	, _inputAccumulatedTime(sf::milliseconds(0))
	, _bulletDeflection(5.0f)
	, _acceleration(15.0f)
	, _maxSquareSpeed(15000.0f)
	, _ordinaryShotTexture(ordinaryShotTexture)
	, _powerfulShotTexture(powerfulShotTexture)
	, _spaceshipAnimationImseq(spaceshipAnimationImseq)
	, _rebound(5.0f)
	, _powerfulRebound(15.0f)
	, _totalBulletCount(200)
	, _totalRocketCount(10)
	, _ordinaryBulletStorage(Pool<OrdinaryBullet>(200))
	, _rocketStorage(Pool<Rocket>(10))
	, _rechargeRocketTime(sf::seconds(3.0f))
	, _rechargeBulletTime(sf::seconds(0.5f))
{
	_speedDirection = NormalizeSpeed();
	_zOrder = 1;
	_spaceshipSprite = new sf::Sprite();
	_spaceshipAnimation = new AnimationPlayer(*_spaceshipSprite, spaceshipAnimationImseq, true);
	_spaceshipSprite->setPosition(position);
	_spaceshipSprite->setOrigin(_spaceshipAnimation->GetWidth() / 2, _spaceshipAnimation->GetHeight() / 2);
	_spaceshipAnimation->Start();
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

	Rocket* rocket = _rocketStorage.Get();
	rocket->Init(_spaceshipSprite->getPosition(), _spaceshipDirection, _powerfulShotTexture.Get());
	
	_rockets.push_back(rocket);
	
	_timeAfterPowerfulShot = sf::seconds(0.0f); 
	GainRebound(_powerfulRebound);
}


void Spaceship::OrdinaryShoot()
{
	if (_timeAfterBulletShot.asSeconds() < _rechargeBulletTime.asSeconds())
	{
		return;
	}
	
	OrdinaryBullet* bulletLeft = _ordinaryBulletStorage.Get();
	bulletLeft->Init(_spaceshipSprite->getPosition(), RotateDirection(_bulletDeflection), _ordinaryShotTexture.Get());

	OrdinaryBullet* bulletRight = _ordinaryBulletStorage.Get();
	bulletRight->Init(_spaceshipSprite->getPosition(), RotateDirection(-_bulletDeflection), _ordinaryShotTexture.Get());

	OrdinaryBullet* bulletCentr = _ordinaryBulletStorage.Get();
	bulletCentr->Init(_spaceshipSprite->getPosition(), RotateDirection(0.0f), _ordinaryShotTexture.Get());
	
	_bullets.push_back(bulletLeft);
	_bullets.push_back(bulletRight);
	_bullets.push_back(bulletCentr);

	_timeAfterBulletShot = sf::seconds(0.0f);
	GainRebound(_rebound);
}

void Spaceship::RotateSpaceship(float angle)
{
	_spaceshipDirection = RotateDirection(angle);

	_currentAngle += angle;
	_spaceshipSprite->setRotation(_currentAngle);	
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

float Spaceship::GetSquareLength(sf::Vector2f speed) const
{
	return speed.x * speed.x + speed.y * speed.y;
}

sf::Vector2f Spaceship::RotateDirection(float angle) const
{
	float radianAngle = angle * PI_F / 180.0f;
	return sf::Vector2f(_spaceshipDirection.x * std::cos(radianAngle) - _spaceshipDirection.y * std::sin(radianAngle),
		_spaceshipDirection.x * std::sin(radianAngle) + _spaceshipDirection.y * std::cos(radianAngle));
}

sf::Vector2f Spaceship::NormalizeSpeed() const
{
	float speedLength = std::sqrt(GetSquareLength(GetSpeed()));
	return GetSpeed() / speedLength;
}

void Spaceship::GainRebound(float reboundValue)
{
	SetSpeed(GetSpeed() + -_spaceshipDirection * reboundValue);
}

void Spaceship::Update(sf::Time deltaTime)
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

	_timeAfterPowerfulShot += deltaTime;
	_timeAfterBulletShot += deltaTime;
	RigidBody::Update(deltaTime.asSeconds());
	_spaceshipSprite->setPosition(RigidBody::GetCoordinates());
	_spaceshipAnimation->Update(deltaTime);

	for (size_t i = 0; i < _bullets.size(); ++i)
	{
		OrdinaryBullet* ptrBullet = _bullets[i];
		
		if (ptrBullet->GetLifeStatus())
		{
			ptrBullet->Update(deltaTime);
		}
		else
		{
			if (!(_ordinaryBulletStorage.Count() == _totalBulletCount)) 
			{
				_bullets.erase(_bullets.cbegin() + i);
				--i;
				_ordinaryBulletStorage.Put(ptrBullet);
				DrawableManager::getInstance()._drawableObjects.erase
				(std::remove(DrawableManager::getInstance()._drawableObjects.begin(), DrawableManager::getInstance()._drawableObjects.end(), static_cast<Drawable*>(ptrBullet)),
					DrawableManager::getInstance()._drawableObjects.end());
			}
		}
	}	
	for (size_t i = 0; i < _rockets.size(); ++i)
	{
		Rocket* ptrRocket = _rockets[i];

		if (ptrRocket->GetLifeStatus())
		{
			ptrRocket->Update(deltaTime);
		}
		else
		{
			if (!(_rocketStorage.Count() == _totalRocketCount))
			{
				_rockets.erase(_rockets.cbegin() + i);
				--i;
				_rocketStorage.Put(ptrRocket);
				DrawableManager::getInstance()._drawableObjects.erase
				(std::remove(DrawableManager::getInstance()._drawableObjects.begin(), DrawableManager::getInstance()._drawableObjects.end(), static_cast<Drawable*>(ptrRocket)), 
					DrawableManager::getInstance()._drawableObjects.end());
			}
		}
	}
}

void Spaceship::Add()
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
	//unsub event
}