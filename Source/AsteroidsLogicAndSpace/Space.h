#pragma once
#include "Asteroid.h"
#include "ParticleSpace.h"
#include "SFML\Graphics.hpp"
#include "Pool.h"
class Space
{
public:
	Space(sf::Sprite &sprite, sf::Rect<int> &borders);

	std::vector<ParticleSpace*> GetStars();

	std::vector<Asteroid*> GetAsteroids();

	~Space();
private:
	sf::Rect<int> _borders;
	/*Pool<Asteroid*> _poolAsteroid;
	Pool<ParticleSpace*> _poolParticle;*/
	std::vector<ParticleSpace*> _stars;
	std::vector<Asteroid*> _asteroids;
	int _nParticleSpace;
	int _nAsteroids;
};
