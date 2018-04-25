#include "Space.h"



Space::Space(const int totalCountAsteroids, const int totalCountStar, const sf::Vector2u windowSize) :
	_poolAsteroid(totalCountAsteroids), _poolStar(totalCountStar),_sizeSpace(windowSize)
{

	
	
}

void Space::AddSomeStars(const int count)
{
	for (int i = 0; i < count; ++i)
	{
		Star* star = _poolStar.Get();
		star->Init(_sizeSpace);
		_stars.push_back(star);
	}
}

void Space::AddSomeAsteroids(const int count, const sf::Sprite& sprite)
{
	for (int i = 1; i <= count; ++i)
	{
		Asteroid* asteroid = _poolAsteroid.Get();
		asteroid->Init(sprite, _sizeSpace);
		_asteroids.push_back(asteroid);
	}
}

void Space::Update()
{

}


Space::~Space()
{
}
