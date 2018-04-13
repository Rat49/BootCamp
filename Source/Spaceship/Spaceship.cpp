#include "Spaceship.h"
#include "SFML\Audio.hpp"

Spaceship::Spaceship(sf::Vector2f spaceshipDirection, sf::Vector2f speed,
	AnimationPlayer& spaceshipAnimation, AnimationPlayer& ordinaryShotAnimation, AnimationPlayer& powerfulShotAnimation)
	: _spaceshipDirection(spaceshipDirection)
	, _speed(speed)
	, _spaceshipAnimation(spaceshipAnimation)
	, _ordinaryShotAnimation(ordinaryShotAnimation)
	, _powerfulShotAnimation(powerfulShotAnimation)
	, _isRecharged(true)
	, _rotationAngle(10.0f)
{

}

void Spaceship::Accelerate()
{
	_speed += _deltaSpeed;
}

void Spaceship::Decelerate()
{
	_speed -= _deltaSpeed;
}

void Spaceship::PowerfulShot()
{
	if (_timeAfterPowerfulShot < _rechargeTime)
		return;

	// something do
	_timeAfterPowerfulShot = sf::seconds(0.0f);
	 
}

void Spaceship::OrdinaryShot()
{
	
}

void Spaceship::RotateSpaceship(float angle)
{
	_spaceshipSprite.setRotation(angle);
}

void Spaceship::ChangeSpeed(sf::Vector2f deltaSpeed)
{
	_speed += deltaSpeed;
}

void Spaceship::Update(sf::Time deltaTime)
{
	_timeAfterPowerfulShot += deltaTime;
	_spaceshipAnimation.Update(deltaTime);
}

Spaceship::~Spaceship()
{

}