#pragma once
#include "Asteroid.h"
#include "Star.h"

class Space
{
public:
	Space(const int totalCountAsteroids, const int totalCountStar, const sf::Vector2u windowSize);
	
	void AddSomeStars(const int count);
	void AddSomeAsteroids(const int count, const sf::Texture texture);

	Pool<Asteroid> _poolAsteroid;
	std::vector<Asteroid *> _asteroids;
	Pool<Star> _poolStar;
	std::vector<Star *> _stars;
	~Space();
private:
	sf::Vector2u _sizeSpace;

};
//
//else
//{
//	for (int j = 0; j < 4; ++j)
//	{
//		if (!poolOwner.Empty())
//		{
//			Asteroid* asteroidNew = poolOwner.Get();
//			asteroidNew->InitFromCrash(_sprite, GetCoordinates(), _type, _sizeSpace);
//			asteroids.push_back(asteroidNew);
//		}
//	}
//	//std::cout << "Broke! ";
//	return true;
//}