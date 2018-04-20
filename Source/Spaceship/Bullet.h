#pragma once
#include "AnimationPlayer.h"
#include "Drawable.h"
#include "ImageSequenceResource.h"
#include "Physics.h"
#include "Pool.h"

class Bullet : public Drawable, public RigidBody, public PoolElement
{
public:
	float _speedValue; 
	bool _life; 

	virtual ~Bullet() = 0 {};
	virtual void Update(sf::Time deltaTime) = 0;
};