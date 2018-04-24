#pragma once
#include "EventSystem.h"
#include "CollisionEvent.h"
#include "BulletManagerEvents.h"
#include "AnimationPlayer.h"
#include "ImageSequenceResource.h"
#include "Input.h"
#include "OrdinaryBullet.h"
#include "Physics.h"
#include "Pool.h"
#include "Rocket.h"
#include <algorithm>

class Spaceship : public RigidBody, public Drawable
{
public:
	Spaceship(sf::Vector2f position, sf::Vector2f speed, InputManager& input, ImageSequenceResource& spaceshipAnimationImseq); 
	~Spaceship();

	void Accelerate();
	void Decelerate();
	void PowerfulShoot();
	void OrdinaryShoot();
	void RotateSpaceship(float angle);	
	void Update(const sf::Time& deltaTime);
	void Add() override;
private:
	const sf::Vector2f _initialDirection;
	sf::Vector2f _spaceshipDirection;
	sf::Vector2f _speedDirection;
	sf::Sprite* _spaceshipSprite;
	AnimationPlayer* _spaceshipAnimation;
	ImageSequenceResource& _spaceshipAnimationImseq;
	const float _rotationAngle;
	const float _acceleration;
	const float _maxSquareSpeed;
	Token_t _tokenForCollisionEventBetweenAsteroidAndSpaceship;
	InputManager& _input;
	const sf::Time _inputTime;
	sf::Time _inputAccumulatedTime;
	const sf::Time _rechargeRocketTime;
	const sf::Time _rechargeBulletTime;
	sf::Time _timeAfterPowerfulShot;
	sf::Time _timeAfterBulletShot;	
	const float _bulletRebound;
	const float _rocketRebound;

	void ControlSpeed(float deltaSpeed);
	float GetSquareLength(sf::Vector2f speed) const;
	sf::Vector2f RotateDirection(float angle) const;
	sf::Vector2f NormalizeSpeed() const;
	void GainRebound(float reboundValue);
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
};