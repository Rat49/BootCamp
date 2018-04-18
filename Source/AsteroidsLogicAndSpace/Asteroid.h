#pragma once
#include "Object.h"

class Asteroid : public Object
{
public:
	Asteroid();
	void Init(sf::Sprite &sprite,sf::RenderWindow & window);
	void Update(sf::Time time) override;
	void Draw() override;
	void Reset() override;
private:
	sf::Sprite _sprite;
	sf::Vector2f _linearVelocity;
	int _radius;
	float _angularVelocity;
	float _rotationSpeed;

};
