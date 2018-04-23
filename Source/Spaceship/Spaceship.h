#pragma once
#include "AnimationPlayer.h"
#include "ImageSequenceResource.h"
#include "Physics.h"
#include "Pool.h"
#include "Input.h"
#include "OrdinaryBullet.h"
#include "Rocket.h"
#include <algorithm>

class Spaceship : public RigidBody, public Drawable
{
public:
	Spaceship(sf::Vector2f position, sf::Vector2f speed, InputManager& input,
		ImageSequenceResource& spaceshipAnimationImseq, TextureResource &ordinaryShotTexture, TextureResource &powerfulShotTexture);
	~Spaceship();

	void Accelerate();
	void Decelerate();
	void PowerfulShoot();
	void OrdinaryShoot();
	void RotateSpaceship(float angle);	
	void Update(sf::Time deltaTime);
	void Add() override;
private:
	Pool<OrdinaryBullet> _ordinaryBulletStorage;
	Pool<Rocket> _rocketStorage;
	std::vector<OrdinaryBullet*> _bullets;
	std::vector<Rocket*> _rockets;

	const sf::Vector2f _initialDirection;
	sf::Vector2f _spaceshipDirection;
	sf::Vector2f _speedDirection;
	const float _rotationAngle;
	float _currentAngle;
	const float _acceleration;
	const sf::Time _rechargeRocketTime;
	const sf::Time _rechargeBulletTime;
	bool _isRecharged;	
	sf::Time _timeAfterPowerfulShot;
	sf::Time _timeAfterBulletShot;
	const sf::Time _inputTime;
	sf::Time _inputAccumulatedTime;
	const float _bulletDeflection;
	const float _maxSquareSpeed;
	const float _rebound;
	const float _powerfulRebound;
	const int _totalBulletCount;
	const int _totalRocketCount;

	sf::Sprite* _spaceshipSprite;
	AnimationPlayer* _spaceshipAnimation;
	ImageSequenceResource& _spaceshipAnimationImseq;
	TextureResource& _ordinaryShotTexture;
	TextureResource& _powerfulShotTexture;

	InputManager& _input;

	void ControlSpeed(float deltaSpeed);
	float GetSquareLength(sf::Vector2f speed) const;
	sf::Vector2f RotateDirection(float angle) const;
	sf::Vector2f NormalizeSpeed() const;
	void GainRebound(float reboundValue);
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
};