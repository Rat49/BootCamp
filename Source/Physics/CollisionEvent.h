
#pragma once
#include "Event.h"

class Spaceship;
class Asteroid;
class Rocket;
class OrdinaryBullet;
class Ammunition;

class CollisionEventBetweenAsteroids : public Event
{
public:
	Asteroid* _asteroid1;
	Asteroid* _asteroid2;
};

class CollisionEventBetweenAsteroidAndBullet : public Event
{
public:
	OrdinaryBullet* _bullet;
	Asteroid* _asteroid;
};

class CollisionEventBetweenAsteroidAndRocket : public Event
{
public:
	Rocket* _rocket;
	Asteroid* _asteroid;
};

class CollisionEventBetweenAsteroidAndSpaceship : public Event
{
public:
	Spaceship* _spaceship;
	Asteroid* _asteroid;
};

class CollisionEventBetweenAmmunitionAndSpaceship : public Event
{
public:
	Spaceship * _spaceship;
	Ammunition* ammunition;
};

class CollisionEventBetweenAmmunitionAndBullet : public Event
{
public:
	OrdinaryBullet * _bullet;
	Ammunition* ammunition;
};

class CollisionEventBetweenAmmunitionAndRocket : public Event
{
public:
	Rocket * _rocket;
	Ammunition* ammunition;
};
