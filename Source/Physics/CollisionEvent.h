#pragma once
#include "EventSystem.h"
#include "Physics.h"
#include "Bullet.h"
#include "Spaceship.h"

class CollisionEventBetweenAsteroids : public Event
{
private:
	RigidBody* _asteroid1;
	RigidBody* _asteroid2;
public:
	void setObjs(RigidBody * o1, RigidBody * o2);
};

class CollisionEventBetweenAsteroidAndBullet : public Event
{
private:
	Bullet* _bullet;
	RigidBody* _asteroid;
public:
	void setObjs(Bullet* o1, RigidBody* o2);
};

class CollisionEventBetweenAsteroidAndSpaceship : public Event
{
private:
	Spaceship* _spaceship;
	RigidBody* _asteroid;
public:
	void setObjs(Spaceship* o1, RigidBody* o2);
};