#pragma once
#include "Drawable.h"
#include "Physics.h"
#include "Pool.h"

class Bullet : public Drawable, public RigidBody, public PoolElement
{
public:
	virtual ~Bullet() = 0 {};
	virtual void Update(sf::Time& deltaTime) = 0;
};