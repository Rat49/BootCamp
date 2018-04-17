#include "Space.h"

Space::Space(sf::Sprite &sprite, sf::Rect<int> &borders)
	:_borders(borders)
{
	_nParticleSpace = (borders.width / 50) * (borders.height / 50);
	_nAsteroids = (borders.width / 200) * (borders.height / 200);
	for (int i = 0; i < _nParticleSpace; ++i)
	{
		ParticleSpace* particle = new ParticleSpace();
		_stars.push_back(particle);
	}
	for (int i = 1; i <= _nAsteroids; ++i)
	{
		Asteroid* asteroid = new Asteroid();
		_asteroids.push_back(asteroid);
	}
}

std::vector<ParticleSpace*> Space::GetStars()
{
	return _stars;
}

std::vector<Asteroid*> Space::GetAsteroids()
{
	return _asteroids;
}

Space::~Space()
{

}