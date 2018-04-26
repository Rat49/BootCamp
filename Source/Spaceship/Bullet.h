#pragma once
#include "CollisionEvent.h"
#include "DrawableManager.h"
#include "Physics.h"
#include "Pool.h"
#include "Mathematics.h"
#include <math.h>

class Bullet : public Drawable, public RigidBody, public PoolElement
{
public:
	virtual ~Bullet() {}
	virtual void Update(const sf::Time& deltaTime) = 0;
};