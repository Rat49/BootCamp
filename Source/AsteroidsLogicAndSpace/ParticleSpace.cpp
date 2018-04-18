#include "ParticleSpace.h"
#include "Mathematics.h"

ParticleSpace::ParticleSpace()
{
	_particle = sf::CircleShape(0);
	_particle.setFillColor(sf::Color(255, 255, 255, 255));
	_particle.setPosition(0,0);
	_depth = 5;
}

void ParticleSpace::Reset()
{
	_particle = sf::CircleShape(0);
	_particle.setFillColor(sf::Color(255, 255, 255, 255));
	_particle.setPosition(0, 0);
	_depth = 5;
}

void ParticleSpace::Init()
{
	_particle = sf::CircleShape(GetFloatRandomValue(0.1, 2));
	_particle.setFillColor(sf::Color(255, 255, 255, GetRandomValue(10, 255)));
	_particle.setPosition(GetRandomValue(0, window->getSize().x), GetRandomValue(0,window->getSize().y));
	_depth = GetFloatRandomValue(5, 9);
}

void ParticleSpace::Update(float time)
{	
	sf::Vector2f coordinates = sf::Vector2f(_particle.getPosition().x, _particle.getPosition().y);
	sf::Vector2f directionFromCenter = sf::Vector2f(coordinates.x - window->getSize().x / 2, coordinates.y - window->getSize().y / 2);
	sf::Vector2f linearVelocity = _depth * 10.0f * GetNormalizedVelocity(directionFromCenter);
	sf::Vector2f nextPosition = coordinates + linearVelocity * time;
	if ((nextPosition.x > window->getSize().x) || (nextPosition.x < 0) || (nextPosition.y > window->getSize().y) || (nextPosition.y < 0))
	{
		nextPosition = sf::Vector2f(GetRandomValue(0, window->getSize().x), GetRandomValue(0, window->getSize().y));
	}
	_particle.setPosition(nextPosition);

}

void ParticleSpace::Draw()
{
	window->draw(_particle);
}

