#include "Input.h"
#include "Physics.h"
#include "Spaceship.h"
#include "DrawableManager.h"
#include <iostream>

const float  PI_F = 3.14159265358979f;

Spaceship::Spaceship(sf::Vector2f position, sf::Vector2f speed, InputManager & input,
	ImageSequenceResource &spaceshipAnimationImseq, ImageSequenceResource &ordinaryShotAnimationImseq, ImageSequenceResource &powerfulShotAnimationImseq)
	: RigidBody(position, speed, spaceshipAnimationImseq.GetWidth() / 2.0f, 1.0f)
	, _spaceshipDirection(sf::Vector2f(0.0f, -1.0f))
	, _input(input)
	, _isRecharged(true)
	, _rotationAngle(10.0f)
	, _currentAngle(0.0f)
	, _inputTime(sf::milliseconds(100))
	, _inputAccumulatedTime(sf::milliseconds(0))
	, _bulletDeltaAngle(5.0f)
	, _deltaSpeed(15.0f)
	, _maxSquareSpeed(5000.0f)
	, _ordinaryShotAnimationImseq(ordinaryShotAnimationImseq)
	, _powerfulShotAnimationImseq(powerfulShotAnimationImseq)
	, _spaceshipAnimationImseq(spaceshipAnimationImseq)
	, _ordinaryBulletStorage(Pool<OrdinaryBullet>(100))
{
	_zOrder = 5;
	_spaceshipSprite = new sf::Sprite();
	_spaceshipAnimation = new AnimationPlayer(*_spaceshipSprite, spaceshipAnimationImseq, true);
	Add();
	_spaceshipSprite->setPosition(position);
	_spaceshipSprite->setOrigin(_spaceshipAnimation->GetWidth() / 2, _spaceshipAnimation->GetHeight() / 2);
	_spaceshipAnimation->Start();
	
}

void Spaceship::Accelerate()
{
	ChangeSpeed(-_deltaSpeed);
}

void Spaceship::Decelerate()
{
	ChangeSpeed(_deltaSpeed);
}

void Spaceship::PowerfulShoot()
{
	if (_timeAfterPowerfulShot < _rechargeTime)
		return;

	//Rocket rocketLeft = Rocket(speedValue * _spaceshipDirection, sprite, animationPlayer);

	_timeAfterPowerfulShot = sf::seconds(0.0f); 
}


void Spaceship::OrdinaryShoot()
{

	sf::Sprite* bulletSprite = new sf::Sprite();
	OrdinaryBullet * bulletLeft = _ordinaryBulletStorage.Get();
	bulletLeft->Init(*bulletSprite, _spaceshipSprite->getPosition(), _spaceshipDirection, _ordinaryShotAnimationImseq.Get()[0]);

	_bullets.push_back(bulletLeft);
}

void Spaceship::RotateSpaceship(float angle)
{
	float radianAngle = angle * PI_F / 180.0f;
	_spaceshipDirection = sf::Vector2f(_spaceshipDirection.x * std::cos(radianAngle) - _spaceshipDirection.y * std::sin(radianAngle),
		                               _spaceshipDirection.x * std::sin(radianAngle) + _spaceshipDirection.y * std::cos(radianAngle));

	_currentAngle += angle;
	_spaceshipSprite->setRotation(_currentAngle);	
}

void Spaceship::ChangeSpeed(float deltaSpeed)
{
	sf::Vector2f newSpeed = GetSpeed() - deltaSpeed * _spaceshipDirection;
	if (GetSquareLength(newSpeed) < _maxSquareSpeed)
	{
		SetSpeed(newSpeed);
	}
}

float Spaceship::GetSquareLength(sf::Vector2f speed) const
{
	return speed.x * speed.x + speed.y * speed.y;
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
	//========================Shoot is not exists in InputManager============================
	if (_input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && stateShoot == ButtonsState::JustPressed)
	{
		OrdinaryShoot();
	}
	//=======================================================================================

	_timeAfterPowerfulShot += deltaTime;
	RigidBody::Update(deltaTime.asSeconds());
	_spaceshipSprite->setPosition(RigidBody::GetCoordinates());
	_spaceshipAnimation->Update(deltaTime);


	for (auto bullet : _bullets)
	{
		bullet->Update(deltaTime);
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

void Spaceship::Draw(sf::RenderWindow & window)
{
	window.draw(*(_spaceshipAnimation->GetSprite()));
}

Spaceship::~Spaceship()
{

}