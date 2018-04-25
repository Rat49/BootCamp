#pragma once
#include "Asteroid.h"
#include "Star.h"

class Space
{
public:
	Space(const int totalCountAsteroids, const int totalCountStar, const sf::Vector2u windowSize);
	
	void AddSomeStars(const int count);
	void AddSomeAsteroids(const int count, const sf::Sprite& sprite);
	void Update();

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

for (size_t i = 0; i < space._asteroids.size(); ++i)
{
	if (space._asteroids[i]->_life == false)
	{
		if (!(space._poolAsteroid.Count() == space._poolAsteroid.MaxCount()))
		{
			space._asteroids[i]->Remove();
			space._poolAsteroid.Put(space._asteroids[i]);
			space._asteroids.erase(std::find(space._asteroids.begin(), space._asteroids.end(), space._asteroids[i]));
			--i;
		}
	}
}

for (auto *asteroid : space._asteroids)
{
	asteroid->Update(physicsStepTargetFrameTime / 1e3);
}
for (auto *star : space._stars)
{
	star->Update(physicsStepTargetFrameTime / 1e3);
}