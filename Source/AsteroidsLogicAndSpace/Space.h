#pragma once
#include "Asteroid.h"
#include "Star.h"

class Space
{
public:
	Space(const int totalCountAsteroids, const int totalCountStar, const sf::Vector2u windowSize);
	
	void AddSomeStars(const int count);
	void AddSomeAsteroids(const int count, const sf::Sprite& sprite);
	void Update(const float physicsStepTargetFrameTime);

	Pool<Asteroid> _poolAsteroid;
	std::vector<Asteroid *> _asteroids;
	Pool<Star> _poolStar;
	std::vector<Star *> _stars;
	~Space();
private:
	sf::Vector2u _sizeSpace;

};
