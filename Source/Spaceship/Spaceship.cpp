#include "Spaceship.h"
#include <iostream>

const float PI_F = 3.14159265358979f;

Spaceship::Spaceship(sf::Vector2f position, sf::Vector2f speed, InputManager & input,
	ImageSequenceResource &spaceshipAnimationImseq, TextureResource &ordinaryShotTexture, TextureResource &powerfulShotTexture)
	: RigidBody(position, speed, spaceshipAnimationImseq.GetWidth() / 2.0f, 1.0f)
	, _spaceshipDirection(_initialDirection)
	, _input(input)
	, _isRecharged(true)
	, _rotationAngle(10.0f)
	, _currentAngle(0.0f)
	, _inputTime(sf::milliseconds(100))
	, _inputAccumulatedTime(sf::milliseconds(0))
	, _bulletDeltaAngle(5.0f)
	, _deltaSpeed(15.0f)
	, _maxSquareSpeed(10000.0f)
	, _ordinaryShotTexture(ordinaryShotTexture)
	, _powerfulShotTexture(powerfulShotTexture)
	, _spaceshipAnimationImseq(spaceshipAnimationImseq)
	, _rebound(5.0f)
	, _powerfulRebound(15.0f)
	, _ordinaryBulletStorage(Pool<OrdinaryBullet>(100))
	, _rocketStorage(Pool<Rocket>(10))
	, _rechargeTime(sf::seconds(3.0f))
{
	_speedDirection = NormalizeSpeed();
	_zOrder = 1;
	_spaceshipSprite = new sf::Sprite();
	_spaceshipAnimation = new AnimationPlayer(*_spaceshipSprite, spaceshipAnimationImseq, true);
	Add();
	_spaceshipSprite->setPosition(position);
	_spaceshipSprite->setOrigin(_spaceshipAnimation->GetWidth() / 2, _spaceshipAnimation->GetHeight() / 2);
	_spaceshipAnimation->Start();
	
}

void Spaceship::Accelerate()
{
	ChangeSpeed(_deltaSpeed);
}

void Spaceship::Decelerate()
{
	ChangeSpeed(-_deltaSpeed);
}

void Spaceship::PowerfulShoot()
{
	if (_timeAfterPowerfulShot.asSeconds() < _rechargeTime.asSeconds())
	{
		return;
	}

	Rocket* rocket = _rocketStorage.Get();
	rocket->Init(_spaceshipSprite->getPosition(), _spaceshipDirection, _powerfulShotTexture.Get());
	
	if (std::find(_rockets.cbegin(), _rockets.cend(), rocket) == _rockets.cend())
	{
		_rockets.push_back(rocket);
	}

	//GetRebound(_powerfulRebound);
	
	_timeAfterPowerfulShot = sf::seconds(0.0f); 
}


void Spaceship::OrdinaryShoot()
{
	OrdinaryBullet* bulletLeft = _ordinaryBulletStorage.Get();
	bulletLeft->Init(_spaceshipSprite->getPosition(), RotateDirection(10.0f), _ordinaryShotTexture.Get());

	OrdinaryBullet* bulletRight = _ordinaryBulletStorage.Get();
	bulletRight->Init(_spaceshipSprite->getPosition(), RotateDirection(-10.0f), _ordinaryShotTexture.Get());

	if (std::find(_bullets.cbegin(), _bullets.cend(), bulletLeft) == _bullets.cend())
	{
		_bullets.push_back(bulletLeft);
	}
	if (std::find(_bullets.cbegin(), _bullets.cend(), bulletRight) == _bullets.cend())
	{
		_bullets.push_back(bulletRight);
	}

	//GetRebound(_rebound);
}

void Spaceship::RotateSpaceship(float angle)
{
	_spaceshipDirection = RotateDirection(angle);

	_currentAngle += angle;
	_spaceshipSprite->setRotation(_currentAngle);	
}

void Spaceship::ChangeSpeed(float deltaSpeed)
{
	sf::Vector2f speed = GetSpeed();
	float angle = std::acos(_speedDirection.x * _spaceshipDirection.x + _speedDirection.y * _spaceshipDirection.y) * 180.0f / PI_F;

	SetSpeed(RotateDirection(GetSpeed(), angle));
	_speedDirection = _spaceshipDirection;

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

sf::Vector2f Spaceship::RotateDirection(sf::Vector2f vector, float angle) const
{
	float radianAngle = angle * PI_F / 180.0f;
	return sf::Vector2f(vector.x * std::cos(radianAngle) - vector.y * std::sin(radianAngle),
		vector.x * std::sin(radianAngle) + vector.y * std::cos(radianAngle));
}

sf::Vector2f Spaceship::NormalizeSpeed() const
{
	float speedLength = std::sqrt(GetSquareLength(GetSpeed()));
	return GetSpeed() / speedLength;
}

void Spaceship::GetRebound(float reboundValue)
{
	sf::Vector2f rebound = -_spaceshipDirection * reboundValue;
	SetSpeed(GetSpeed() - rebound);
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
	RigidBody::Update(deltaTime.asSeconds());
	_spaceshipSprite->setPosition(RigidBody::GetCoordinates());
	_spaceshipAnimation->Update(deltaTime);

	for (auto bullet : _bullets)
	{
		if (bullet->GetLifeStatus())
		{
			bullet->Update(deltaTime);
		}
		else
		{
			_ordinaryBulletStorage.Put(bullet);
			bullet->Reset();
		}
	}
	for (auto rocket : _rockets)
	{
		if (rocket->GetLifeStatus())
		{
			rocket->Update(deltaTime);
		}
		else
		{
			_rocketStorage.Put(rocket);
			rocket->Reset();
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
}