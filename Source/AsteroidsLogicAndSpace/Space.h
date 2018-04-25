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

	std::vector<Asteroid *> _asteroids;

	~Space();
private:
	Pool<Asteroid> _poolAsteroid;
	std::vector<Star *> _stars;
	Pool<Star> _poolStar;
	
	sf::Vector2u _sizeSpace;

};
