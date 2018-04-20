#pragma once
#include "Object.h"
class Asteroid : public Object
{
public:
	Asteroid();
	void Init(sf::Sprite &sprite,sf::Vector2u size);
	void InitFromCrash(sf::Sprite & sprite,sf::Vector2f position, float preHealth);
	void Update(sf::Time time) override;
	void Draw(sf::RenderWindow &window) override;
	void Reset() override;
	
private:
	sf::Sprite _sprite;
	sf::Vector2f _linearVelocity;
	float _angularVelocity;
	float _rotationSpeed;
	int _radius;
	float _halfLenght;
	void DefaultInit();
	void RandomInit();

};
