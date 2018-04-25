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

void Space::Update(const float physicsStepTargetFrameTime)
{
	for (size_t i = 0; i < _asteroids.size(); ++i)
	{ 
		Asteroid *asteroid = _asteroids[i];
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
						_asteroids.push_back(asteroidNew);
					}
				}
			}

			if (!(_poolAsteroid.Count() == _poolAsteroid.MaxCount()))
			{
				asteroid->Remove();
				_poolAsteroid.Put(asteroid);
				_asteroids.erase(std::find(_asteroids.begin(), _asteroids.end(), asteroid));
				--i;
			}
		}
		asteroid->Update(physicsStepTargetFrameTime);
	}

	for (auto *star : _stars)
	{
		star->Update(physicsStepTargetFrameTime);
	}
}


Space::~Space()
{

	for (auto &asteroid : _asteroids)
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
