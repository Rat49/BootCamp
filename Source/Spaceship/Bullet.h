#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"
#include "Drawable.h"

class Bullet : public Drawable
{
public:
	float _speed; // = _spaceshipDirection
	bool _life; //???

	virtual ~Bullet() = 0 {};
	virtual void Update(sf::Time deltaTime) = 0;
};