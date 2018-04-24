#pragma once
#include "CollisionEvent.h"
#include "DrawableManager.h"
#include "Physics.h"
#include "Pool.h"

class Bullet : public Drawable, public RigidBody, public PoolElement
{
public:
	virtual ~Bullet() = 0 {};
	virtual void Update(const sf::Time& deltaTime) = 0;
};