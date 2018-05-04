#pragma once
#include "AnimationPlayer.h"
#include "Object.h"
#include "Physics.h"
#include "Event.h"
#include "CollisionEvent.h"
#include "ResourceManager.h"
#include <vector>

enum class AmmunitionSize : uint8_t
{
	Small,
	Medium,
	Big
};

enum class AmmunitionType : uint8_t
{
	Bullet,
	Rocket,
	Aid
};

static const std::vector<int> ammunitionCapacity = { 15, 30, 60, 2, 4, 8, 30, 50, 100 };

class Ammunition : public Drawable, public RigidBody
{
private:
	void OnAsteroidCollisionHandler(const Event & cEvent);
	void OnSpaceshipCollisionHandler(const Event & cEvent);
	void OnRocketCollisionHandler(const Event & cEvent);
	void OnBulletCollisionHandler(const Event & cEvent);
	void AddToDrawableManager();
	void RandomInit();

	sf::Sprite* _sprite;
	AnimationPlayer* _spaceshipAnimation;
	std::vector<std::pair<AnimationPlayer*, AnimationPlayer*>> _animations;
	uint8_t ammunitionNumber;

	sf::Vector2f _linearVelocity; 
	float _angularVelocity;
	float _rotationSpeed;
	float _radius;
	float _halfLenght;
	float _startScale;
	float _spawnBoundHeight;
	float _spawnBoundWidth;

	float _hp = 100.f;
	float _cLifeTime = 0.f;
	float _cRespawnTime = 5.f;
	const float _lifeTime = 20.f;
	const float _respawnTime = 5.f;


public:
	void Init();
	Ammunition(ResourceManager *rm);

	AmmunitionType _ammunitionType;
	AmmunitionSize _ammunitionSize;
	unsigned int capacity;

	int GetZOrder() const override;
	
	void Update(float time);
	void Draw(sf::RenderWindow &window) override;
	~Ammunition();
};

