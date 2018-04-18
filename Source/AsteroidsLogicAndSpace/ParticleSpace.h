#pragma once
#include "Object.h"

class ParticleSpace : public Object
{
public:
	ParticleSpace();
	void Init(sf::RenderWindow & window);
	void Update(sf::Time time) override;
	void Draw() override;
	void Reset() override;
private:
	sf::CircleShape _particle;
	int _alfaColor;
	float _depth;
	float _radius;
	sf::Vector2f GetRandomPosition();
};
