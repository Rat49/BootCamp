#pragma once
#include "EventSystem.h"
#include "CollisionEvent.h"
#include "BulletManagerEvents.h"
#include "AnimationPlayer.h"
#include "ImageSequenceResource.h"
#include "Input.h"
#include "Physics.h"
#include "Pool.h"
#include "DrawableManager.h"
#include "Mathematics.h"
#include <math.h>
#include <algorithm>

class Spaceship : public RigidBody, public Drawable
{
public:
	Spaceship(const sf::Vector2f& position, const sf::Vector2f& speed, InputManager& input, 
		ImageSequenceResource& spaceshipAnimationImseq, ImageSequenceResource& spaceshipFlickeringImseq);
	~Spaceship();

	void Accelerate();
	void Decelerate();
	void PowerfulShoot();
	void OrdinaryShoot();
	void RotateSpaceship(float angle);
	void Update(const sf::Time& deltaTime);
	void AddToDrawableManager() override;
	void OnCollisionHandler(const Event& event);
private:
	unsigned int _liveCount;
	bool _isDamaged;
	const sf::Vector2f _initialDirection;
	sf::Vector2f _spaceshipDirection;
	sf::Vector2f _speedDirection;
	sf::Sprite* _spaceshipSprite;
	AnimationPlayer* _spaceshipAnimation;
	ImageSequenceResource& _spaceshipAnimationImseq;
	AnimationPlayer* _spaceshipFlickering;
	ImageSequenceResource& _spaceshipFlickeringImseq;
	const float _rotationAngle;
	const float _acceleration;
	const float _maxSquareSpeed;
	sf::Time _flickeringTime;
	sf::Time _timeAfterDamage;
	const float _shotIndentValue;

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
	void GainRebound(float reboundValue);
	void SetFlickeringMode();
	void SetNormalMode();
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
};