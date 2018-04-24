#pragma once
#include "Asteroid.h"
#include "Star.h"
class Space
{
public:
	Space();
	~Space();
private:
	const int totalCountAsteroids = 100;
	Pool<Asteroid> poolAsteroid(totalCountAsteroids);
	std::vector<Asteroid *> asteroids;
	const int totalCountStar = (WINDOW_WIDTH / 50) * (WINDOW_HEIGHT / 50) + 10;
	Pool<Star> poolStar(totalCountStar);
};

