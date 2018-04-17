#include "Input.h"
#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager& input,
	AnimationPlayer& spaceshipAnimation)//, AnimationPlayer& ordinaryShotAnimation, AnimationPlayer& powerfulShotAnimation)
	: _spaceshipDirection(spaceshipDirection)
	, _speed(speed)
	, _input(input)
	, _spaceshipAnimation(spaceshipAnimation)
	//, _ordinaryShotAnimation(ordinaryShotAnimation)
	//, _powerfulShotAnimation(powerfulShotAnimation)
	, _spaceshipSprite(spaceshipAnimation.GetSprite())
	, _isRecharged(true)
	, _rotationAngle(10.0f)
	, _rebound(0.001f)
	, _powerfulRebound(0.1f)
	, _currentAngle(0.0f)
	, _inputFrequency(sf::milliseconds(100))
	, _inputTime(sf::milliseconds(0))
	, _bulletDeltaAngle(5.0f)
	, _deltaSpeed(sf::Vector2f(1.0f, 1.0f))
	, _maxSquareSpeed(500.0f)
{
	_spaceshipSprite->setPosition(200.0f, 200.0f);
	_spaceshipSprite->setOrigin(_spaceshipAnimation.GetWidth() / 2, _spaceshipAnimation.GetHeight() / 2);
}

void Spaceship::Accelerate()
{
	sf::Vector2f newSpeed = _speed + _deltaSpeed;
	if (GetSquareSpeed(newSpeed) < _maxSquareSpeed)
	{
		_speed = newSpeed;
	}
}

void Spaceship::Decelerate()
{
	sf::Vector2f newSpeed = _speed - _deltaSpeed;
	if (GetSquareSpeed(newSpeed) < _maxSquareSpeed)
	{
		_speed = newSpeed;
	}
}

void Spaceship::PowerfulShoot()
{
	if (_timeAfterPowerfulShot < _rechargeTime)
		return;

	//Rocket rocketLeft = Rocket(speedValue * _spaceshipDirection, sprite, animationPlayer);
	
	_speed = sf::Vector2f(_speed.x - _spaceshipDirection.x * _powerfulRebound, _speed.y - _spaceshipDirection.y * _powerfulRebound);
	//==========================only for test=======================================
	std::cout << "PowerfulShoot" << std::endl;
	std::cout << _speed.x << " " << _speed.y << std::endl;
	//==============================================================================
	// SetSpeed()

	_timeAfterPowerfulShot = sf::seconds(0.0f); 
}

void Spaceship::OrdinaryShoot()
{
	sf::Transform rotation;
	rotation.rotate(_bulletDeltaAngle, _spaceshipSprite->getOrigin());
	sf::Vector2f bulletLeftDirection = rotation.transformPoint(_spaceshipDirection);
	OrdinaryBullet bulletLeft = OrdinaryBullet(bulletLeftDirection, *_ordinaryShotAnimation);

	rotation.rotate(-_bulletDeltaAngle, _spaceshipSprite->getOrigin());
	sf::Vector2f bulletRightDirection = rotation.transformPoint(_spaceshipDirection);
	OrdinaryBullet bulletRight = OrdinaryBullet(bulletRightDirection, *_ordinaryShotAnimation);

	_speed = sf::Vector2f(_speed.x - _spaceshipDirection.x * _rebound, _speed.y - _spaceshipDirection.y * _rebound);
	//==========================only for test=======================================
	std::cout << "OrdinaryShoot" << std::endl;
	std::cout << _speed.x << " " << _speed.y << std::endl;
	//==============================================================================
	// SetSpeed()
}

void Spaceship::RotateSpaceship(float angle)
{
	//==========================only for test=======================================
	//std::cout << "Rotation" << std::endl;
	//std::cout << _spaceshipDirection.x << " " << _spaceshipDirection.y << std::endl;
	//==============================================================================
	sf::Transform rotation;
	rotation.rotate(angle, _spaceshipSprite->getOrigin());
	_spaceshipDirection = rotation.transformPoint(_spaceshipDirection);
	//==========================only for test=======================================
	//std::cout << _spaceshipDirection.x << " " << _spaceshipDirection.y << std::endl;
	//==============================================================================

	_currentAngle += angle;
	_spaceshipSprite->setRotation(_currentAngle);	
}

void Spaceship::ChangeSpeed(sf::Vector2f deltaSpeed)
{
	_speed += deltaSpeed;
}

float Spaceship::GetSquareSpeed(sf::Vector2f speed) const
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
		if (_inputTime < _inputFrequency)
		{
			_inputTime += deltaTime;
		}
		else 
		{
			RotateSpaceship(-_rotationAngle);
			_inputTime = sf::milliseconds(0);
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveRight), stateMoveRight) && (stateMoveRight == ButtonsState::JustPressed || stateMoveRight == ButtonsState::Pressed))
	{
		if (_inputTime < _inputFrequency)
		{
			_inputTime += deltaTime;
		}
		else
		{
			RotateSpaceship(_rotationAngle);
			_inputTime = sf::milliseconds(0);
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveUp), stateMoveUp) && (stateMoveUp == ButtonsState::JustPressed || stateMoveUp == ButtonsState::Pressed))
	{
		if (_inputTime < _inputFrequency)
		{
			_inputTime += deltaTime;
		}
		else
		{
			Accelerate();
			_inputTime = sf::milliseconds(0);
			//==========================only for test=======================================
			std::cout << _speed.x << " " << _speed.y << std::endl;
			//==============================================================================
		}
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveDown), stateMoveDown) && (stateMoveDown == ButtonsState::JustPressed || stateMoveDown == ButtonsState::Pressed))
	{
		if (_inputTime < _inputFrequency)
		{
			_inputTime += deltaTime;
		}
		else
		{
			Decelerate();
			_inputTime = sf::milliseconds(0);
			//==========================only for test=======================================
			std::cout << _speed.x << " " << _speed.y << std::endl;
			//==============================================================================
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
	// RigidBody::Update();
	_spaceshipAnimation.Update(deltaTime);
}

void Spaceship::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(*_spaceshipSprite);
}

void Spaceship::TestDraw(sf::RenderWindow window)
{
	
}



Spaceship::~Spaceship()
{

}