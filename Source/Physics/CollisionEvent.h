#pragma once
#include "EventSystem.h"

class Spaceship;
class RigidBody;
class Rocket;
class OrdinaryBullet;

class CollisionEventBetweenAsteroids : public Event
{
public:
	RigidBody* _asteroid1;
	RigidBody* _asteroid2;
};

class CollisionEventBetweenAsteroidAndBullet : public Event
{
public:
	OrdinaryBullet* _bullet;
	RigidBody* _asteroid;
};

class CollisionEventBetweenAsteroidAndRocket : public Event
{
public:
	Rocket* _bullet;
	RigidBody* _asteroid;
};

class CollisionEventBetweenAsteroidAndSpaceship : public Event
{
public:
	Spaceship* _spaceship;
	RigidBody* _asteroid;
};