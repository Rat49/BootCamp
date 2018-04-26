#pragma once
#include "AnimationPlayer.h"
#include "BulletManagerEvents.h"
#include "CollisionEvent.h"
#include "DrawableManager.h"
#include "EventSystem.h"
#include "GameOverEvent.h"
#include "ImageSequenceResource.h"
#include "Input.h"
#include "Mathematics.h"
#include "Physics.h"
#include "Pool.h"
#include "SpaceshipRespawnEvent.h"

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
private:
	unsigned int _liveCount;
	unsigned int _HP;
	bool _isDamaged;
	const sf::Vector2f _initialDirection;
	sf::Vector2f _spaceshipDirection;
	sf::Vector2f _speedDirection;
	sf::Sprite* _spaceshipSprite;
	sf::Vector2f _spaceshipScale;
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