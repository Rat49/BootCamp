#pragma once
#include "AnimationPlayer.h"
#include "ImageSequenceResource.h"
#include "OrdinaryBullet.h"
#include "Physics.h"
#include "Pool.h"
#include "Rocket.h"


class Spaceship : public RigidBody, public Drawable
{
public:
	//Spaceship(sf::Vector2f position, sf::Vector2f spaceshipDirection, sf::Vector2f speed, InputManager& input,
	//	AnimationPlayer* spaceshipAnimation, AnimationPlayer* ordinaryShotAnimation, AnimationPlayer* powerfulShotAnimation);

	Spaceship(sf::Vector2f position, sf::Vector2f speed, InputManager& input,
		ImageSequenceResource& spaceshipAnimationImseq, ImageSequenceResource& ordinaryShotAnimationImseq, ImageSequenceResource& powerfulShotAnimationImseq);

	void Accelerate();
	void Decelerate();
	void PowerfulShoot();
	void OrdinaryShoot();
	void RotateSpaceship(float angle);	
	void Update(sf::Time deltaTime);

	~Spaceship();

private:
	//Pool<OrdinaryBullet> _ordinaryBulletStorage;
	//Pool<Rocket> _rocketStorage;

	sf::Vector2f _spaceshipDirection;

	const float _rotationAngle;
	float _currentAngle;
	const float _deltaSpeed;
	const sf::Time _rechargeTime;
	bool _isRecharged;	
	sf::Time _timeAfterPowerfulShot;
	const sf::Time _inputTime;
	sf::Time _inputAccumulatedTime;
	const float _bulletDeltaAngle;
	const float _maxSquareSpeed;

	std::vector<OrdinaryBullet*> _bullets;

	sf::Sprite* _spaceshipSprite;
	AnimationPlayer* _spaceshipAnimation;

	ImageSequenceResource& _spaceshipAnimationImseq;
	ImageSequenceResource& _ordinaryShotAnimationImseq;
	ImageSequenceResource& _powerfulShotAnimationImseq;

	InputManager& _input;

	void ChangeSpeed(float deltaSpeed);
	float GetSquareLength(sf::Vector2f speed) const;

	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
};