#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"

class Spaceship //: public Physics 
{
public:
	Spaceship(sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager& input,
		AnimationPlayer& spaceshipAnimation);// AnimationPlayer& ordinaryShotAnimation, AnimationPlayer& powerfulShotAnimation);

	void Accelerate();
	void Decelerate();
	void PowerfulShoot();
	void OrdinaryShoot();
	void RotateSpaceship(float angle);
	void ChangeSpeed(sf::Vector2f deltaSpeed);
	void Update(sf::Time deltaTime);

	~Spaceship();

private:
	sf::Vector2f _speed;  //remove when include physics
	sf::Vector2f _spaceshipDirection;

	const float _rotationAngle;
	float _currentAngle;
	const sf::Vector2f _deltaSpeed;
	const sf::Time _rechargeTime;
	bool _isRecharged;	
	sf::Time _timeAfterPowerfulShot;
	const float _rebound;
	const float _powerfulRebound;

	sf::Sprite* _spaceshipSprite;
	sf::Sprite* _ordinaryShootAnimation;
	sf::Sprite* _powerfulShootAnimation;
	AnimationPlayer& _spaceshipAnimation;
	//AnimationPlayer& _ordinaryShotAnimation;
	//AnimationPlayer& _powerfulShotAnimation;

	InputManager& _input;
};