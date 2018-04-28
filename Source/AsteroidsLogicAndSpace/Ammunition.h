#pragma once
#pragma once
#include "Object.h"
#include "Physics.h"
#include "Event.h"
#include "CollisionEvent.h"
#include "ResourceManager.h"

enum class AmmunitionSize : uint8_t
{
	Small,
	Middle,
	Big
};

enum class AmmunitionType : uint8_t
{
	Bullet,
	Rocket
};

class Ammunition : public Drawable, public RigidBody
{
	
public:
	void Init();
	Ammunition(ResourceManager *rm);

	void OnSpaceshipCollisionHandler(const Event & cEvent);

	void OnRocketCollisionHandler(const Event & cEvent);


	AmmunitionType _ammunitionType;
	AmmunitionSize _ammunitionSize;
	void OnBulletCollisionHandler(const Event & cEvent);
	void AddToDrawableManager();
	int GetZOrder() const override;

	sf::Sprite _sprite;
	std::vector<sf::Sprite> _sprites;
	sf::Vector2f _linearVelocity;
	float _angularVelocity;
	float _rotationSpeed;
	float _radius;
	float _halfLenght;
	float _startScale;
	float _spawnBoundHeight;
	float _spawnBoundWidth;
	bool _life = true;

	void Update(float time);
	void Draw(sf::RenderWindow &window) override;
	Ammunition();
	~Ammunition();
};

