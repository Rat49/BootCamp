#include "SpaceParticle.h"

float GetRandomValue(float start, int end)
{
	return start + rand() % end;
}

SpaceParticle::SpaceParticle()
{
	sf::CircleShape particle(GetRandomValue);
}

void SpaceParticle::Update(float time)
{

}

SpaceParticle::~SpaceParticle()
{

}