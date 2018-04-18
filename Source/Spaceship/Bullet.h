#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"
#include "Drawable.h"
#include "Physics.h"

class Bullet : public Drawable, public RigidBody
{
public:
	float _speedValue; 
	bool _life; //???

	virtual ~Bullet() = 0 {};
	virtual void Update(sf::Time deltaTime) = 0;
};