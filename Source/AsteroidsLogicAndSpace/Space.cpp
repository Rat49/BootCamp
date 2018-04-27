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
		asteroids.push_back(asteroid);
	}
}

void Space::Update(const sf::Time& deltaTime)
{
	for (size_t i = 0; i < asteroids.size(); ++i)
	{ 
		Asteroid *asteroid = asteroids[i];
		if (asteroid->_life == false)
		{
			if (asteroid->_type != AsteroidType::Small)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (!_poolAsteroid.Empty())
		     			{
						Asteroid* asteroidNew = _poolAsteroid.Get();
						asteroidNew->InitFromCrash(asteroid->_sprite, asteroid->GetCoordinates(), asteroid->_type, _sizeSpace);
						asteroids.push_back(asteroidNew);
					}
				}
			}

			if (!(_poolAsteroid.Count() == _poolAsteroid.MaxCount()))
			{
				asteroid->Remove();
				_poolAsteroid.Put(asteroid);
				asteroids.erase(std::find(asteroids.begin(), asteroids.end(), asteroid));
				--i;
				++_countSmallDeadAsteroids;
			}
			if (_countSmallDeadAsteroids >= 16)
			{
				Asteroid* asteroidNew = _poolAsteroid.Get();
				asteroidNew->InitFromCrash(asteroid->_sprite, asteroid->GetCoordinates(), asteroid->_type, _sizeSpace);
				asteroids.push_back(asteroidNew);
				_countSmallDeadAsteroids = 0;
      			} 
		}
		asteroid->Update(deltaTime.asSeconds());
	}

	for (auto *star : _stars)
	{
		star->Update(deltaTime.asSeconds());
	}
}


Space::~Space()
{

	for (auto &asteroid : asteroids)
	{
		if (!(_poolAsteroid.Count() == _poolAsteroid.MaxCount()))
		{
			asteroid->Remove();
			_poolAsteroid.Put(asteroid);
		}
	}

	for (auto &star : _stars)
	{
		if (!(_poolStar.Count() == _poolStar.MaxCount()))
		{
			star->Remove();
			_poolStar.Put(star);
		}
	}
}
