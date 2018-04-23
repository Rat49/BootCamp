#pragma once
#include "Event.h"
#include "Physics.h"
#include <vector>
#include "Pool.h"

class CollisionEvent : public Event
{
public:
	CollisionEvent() {};
	~CollisionEvent(){};
	RigidBody *_obj1, *_obj2;
	std::vector<RigidBody*> *_owner;
	Pool<RigidBody*> *_poolOwner;
};
