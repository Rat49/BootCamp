#include "Input.h"
#include "Spaceship.h"
#include <iostream>

Spaceship::Spaceship(sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager& input,
	AnimationPlayer& spaceshipAnimation)// AnimationPlayer& ordinaryShotAnimation, AnimationPlayer& powerfulShotAnimation)
	: _spaceshipDirection(spaceshipDirection)
	, _speed(speed)
	, _input(input)
	, _spaceshipAnimation(spaceshipAnimation)
	//, _ordinaryShotAnimation(ordinaryShotAnimation)
	// , _powerfulShotAnimation(powerfulShotAnimation)
	, _spaceshipSprite(spaceshipAnimation.GetSprite())
	, _isRecharged(true)
	, _rotationAngle(5.0f)
	, _rebound(0.001f)
	, _powerfulRebound(0.1f)
	, _currentAngle(0.0f)
{
	_spaceshipSprite->setPosition(200.0f, 200.0f);
	_spaceshipSprite->setOrigin(_spaceshipAnimation.GetWidth() / 2, _spaceshipAnimation.GetHeight() / 2);
}

void Spaceship::Accelerate()
{
	_speed += _deltaSpeed;
}

void Spaceship::Decelerate()
{
	_speed -= _deltaSpeed;
}

void Spaceship::PowerfulShoot()
{
	if (_timeAfterPowerfulShot < _rechargeTime)
		return;

	// something do
	_speed = sf::Vector2f(_speed.x + _spaceshipDirection.x * _powerfulRebound, _speed.y + _spaceshipDirection.y * _powerfulRebound);
	// SetSpeed()

	_timeAfterPowerfulShot = sf::seconds(0.0f);
	 
}

void Spaceship::OrdinaryShoot()
{
	// something do
	_speed = sf::Vector2f(_speed.x + _spaceshipDirection.x * _rebound, _speed.y + _spaceshipDirection.y * _rebound);
	// SetSpeed()
}

void Spaceship::RotateSpaceship(float angle)
{
	// do not rotate =(
	sf::Transform rotation;
	rotation.rotate(angle);
	_spaceshipDirection = rotation.transformPoint(_spaceshipDirection);
	//std::cout << _spaceshipDirection.x << " " <<_spaceshipDirection.y << std::endl;
	//=============================================================================

	_currentAngle += angle;
	_spaceshipSprite->setRotation(_currentAngle);
}

void Spaceship::ChangeSpeed(sf::Vector2f deltaSpeed)
{
	_speed += deltaSpeed;
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
		Shoot
	};
	//====================================

	ButtonsState stateMoveLeft;
	ButtonsState stateMoveRight;
	ButtonsState stateShoot;

	_input.Update();
	if (_input.GetState(static_cast<int>(GameActions::MoveLeft), stateMoveLeft) && (stateMoveLeft == ButtonsState::JustPressed || stateMoveLeft == ButtonsState::Pressed))
	{
		RotateSpaceship(-_rotationAngle);
	}
	if (_input.GetState(static_cast<int>(GameActions::MoveRight), stateMoveRight) && (stateMoveRight == ButtonsState::JustPressed || stateMoveRight == ButtonsState::Pressed))
	{
		RotateSpaceship(_rotationAngle);
	}
	if (_input.GetState(static_cast<int>(GameActions::Shoot), stateShoot) && stateShoot == ButtonsState::JustPressed)
	{
		PowerfulShoot();
	}

	_timeAfterPowerfulShot += deltaTime;
	_spaceshipAnimation.Update(deltaTime);
}

Spaceship::~Spaceship()
{

}