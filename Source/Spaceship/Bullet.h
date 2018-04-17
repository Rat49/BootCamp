#pragma once
#include "ImageSequenceResource.h"
#include "AnimationPlayer.h"

class Bullet //: public Physics 
{
public:
	sf::Vector2f _speed; // = _spaceshipDirection
	bool _life; //???

	virtual ~Bullet() = 0 {};
	virtual void Update() = 0;
};