#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"


class Spaceship //: public Physics 
{
public:
	Spaceship(sf::Vector2f spaceshipDirection, sf::Vector2f speed, 
		AnimationPlayer& spaceshipAnimation, AnimationPlayer& ordinaryShotAnimation, AnimationPlayer& powerfulShotAnimation);

	void Accelerate();
	void Decelerate();
	void PowerfulShot();
	void OrdinaryShot();
	void RotateSpaceship(float angle);
	void ChangeSpeed(sf::Vector2f deltaSpeed);
	void Update(sf::Time deltaTime);

	~Spaceship();

private:
	sf::Vector2f _speed;  //remove when include physics
	sf::Vector2f _spaceshipDirection;

	const float _rotationAngle;
	const sf::Vector2f _deltaSpeed;
	const sf::Time _rechargeTime;
	bool _isRecharged;	
	sf::Time _timeAfterPowerfulShot;

	sf::Sprite _spaceshipSprite;
	sf::Sprite _ordinaryShotAnimation;
	sf::Sprite _powerfulShotAnimation;
	AnimationPlayer& _spaceshipAnimation;
	AnimationPlayer& _ordinaryShotAnimation;
	AnimationPlayer& _powerfulShotAnimation;
};