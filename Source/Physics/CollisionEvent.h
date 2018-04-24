#pragma once
#include "Asteroid.h"
#include "EventSystem.h"
#include "Bullet.h"
#include "Spaceship.h"

class CollisionEventBetweenAsteroids : public Event
{
public:
	Asteroid* _asteroid1;
	Asteroid* _asteroid2;
};

class CollisionEventBetweenAsteroidAndBullet : public Event
{
public:
	Bullet* _bullet;
	Asteroid* _asteroid;
};

class CollisionEventBetweenAsteroidAndSpaceship : public Event
{
	Spaceship* _spaceship;
	Asteroid* _asteroid;
};