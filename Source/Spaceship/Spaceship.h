#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"
#include "OrdinaryBullet.h"

class Spaceship : public sf::Drawable//, public Physics 
{
public:
	Spaceship(sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager& input,
		AnimationPlayer& spaceshipAnimation);//, AnimationPlayer& ordinaryShotAnimation, AnimationPlayer& powerfulShotAnimation);

	void Accelerate();
	void Decelerate();
	void PowerfulShoot();
	void OrdinaryShoot();
	void RotateSpaceship(float angle);	
	void Update(sf::Time deltaTime);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void TestDraw(sf::RenderWindow window);

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
	const sf::Time _inputFrequency;
	sf::Time _inputTime;
	const float _bulletDeltaAngle;
	const float _maxSquareSpeed;

	sf::Sprite* _spaceshipSprite;
	sf::Sprite* _ordinaryShootSprite;
	sf::Sprite* _powerfulShootSprite;
	AnimationPlayer& _spaceshipAnimation;
	//AnimationPlayer& _ordinaryShotAnimation;
	//AnimationPlayer& _powerfulShotAnimation;
	// tmp!
	AnimationPlayer* _ordinaryShotAnimation;
	AnimationPlayer* _powerfulShotAnimation;

	InputManager& _input;

	void ChangeSpeed(sf::Vector2f deltaSpeed);
	float GetSquareSpeed(sf::Vector2f speed) const;
};