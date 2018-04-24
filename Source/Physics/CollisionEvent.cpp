#include "CollisionEvent.h"

void CollisionEventBetweenAsteroids::setObjs(RigidBody* o1, RigidBody* o2)
{
	_asteroid1 = o1;
	_asteroid2 = o2;
}

void CollisionEventBetweenAsteroidAndBullet::setObjs(Bullet * o1, RigidBody * o2)
{
	_bullet = o1;
	_asteroid = o2;
}

void CollisionEventBetweenAsteroidAndSpaceship::setObjs(Spaceship * o1, RigidBody * o2)
{
	_spaceship = o1;
	_asteroid = o2;
}
