#pragma once
#include "Object.h"

class ParticleSpace : public Object
{
public:
	ParticleSpace();
	void Init(sf::RenderWindow & window);
	void Update(float time) override;
	void Draw() override;
	void Reset() override;
private:
	sf::CircleShape _particle;
	float _depth;
};
