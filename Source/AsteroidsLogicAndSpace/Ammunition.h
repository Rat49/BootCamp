#pragma once
#pragma once
#include "Object.h"
#include "Physics.h"
#include "Event.h"
#include "CollisionEvent.h"

enum class AmmunitionSize : uint8_t
{
	Small,
	Middle,
	Big,
	Count
};

enum class AmmunitionType : uint8_t
{
	Bullet,
	Rocket,
	Count
};

class Ammunition : public Drawable, public RigidBody
{
	void Init();
public:
	
	Ammunition(sf::Sprite sprite);

	void OnSpaceshipCollisionHandler(const Event & cEvent);

	void OnRocketCollisionHandler(const Event & cEvent);


	AmmunitionType _type;
	AmmunitionSize _size;
	void OnBulletCollisionHandler(const Event & cEvent);
	void AddToDrawableManager();
	int GetZOrder() const override;


	sf::Sprite _sprite;
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

