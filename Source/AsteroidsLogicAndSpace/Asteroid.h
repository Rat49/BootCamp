#pragma once
#include "Object.h"
#include "Physics.h"
#include "Event.h"
#include "CollisionEvent.h"
enum class AsteroidType : uint8_t
{
	Small,
	Middle,
	Big,
	Count
};

class Asteroid : public Object, public RigidBody
{
public:

	Asteroid();

	void Init(const sf::Sprite &sprite, const sf::Vector2u &size);
	void InitFromCrash(const sf::Sprite &sprite, const sf::Vector2f &position, const AsteroidType type, const sf::Vector2u &size);
	void Update(float time) override;
	void Draw(sf::RenderWindow &window) override;
	void Reset() override;
	static void  OnCollisionHandler(const Event& cEvent);
	static void Handler(const CollisionEvent& cEvent);
	
	AsteroidType _type;
	float _health;
	
private:

	sf::Sprite _sprite;
	sf::Vector2f _linearVelocity;
	float _angularVelocity;
	float _rotationSpeed;
	int _radius;
	float _halfLenght;
	float _startScale;
	void DefaultInit();
	void RandomInit();
	void SetParametersFromType(AsteroidType type);

};
