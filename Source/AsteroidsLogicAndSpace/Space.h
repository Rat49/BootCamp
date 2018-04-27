#pragma once
#include "Asteroid.h"
#include "Star.h"
#include "Ammunition.h"
#include "ResourceManager.h"

class Space
{
public:
	Space(const int totalCountAsteroids, const int totalCountStar, const sf::Vector2u windowSize);

	void AddAmmunition(ResourceManager *rm);
	
	void AddSomeStars(const int count);
	void AddSomeAsteroids(const int count, const sf::Sprite& sprite);
	void Update(const float physicsStepTargetFrameTime);

	std::vector<Asteroid *> asteroids;
	Ammunition* ammunition;

	~Space();
private:
	Pool<Asteroid> _poolAsteroid;
	std::vector<Star *> _stars;
	Pool<Star> _poolStar;
	
	sf::Vector2u _sizeSpace;

};
