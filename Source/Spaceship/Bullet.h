#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"

class Bullet : public sf::Drawable//, public PoolElement
{
public:
	float _speed; // = _spaceshipDirection
	bool _life; //???

	virtual ~Bullet() = 0 {};
	virtual void Update(sf::Time deltaTime) = 0;
};