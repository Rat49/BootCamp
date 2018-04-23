#pragma once
#include "EventSystem.h"
#include "Physics.h"

class CollisionEvent : public Event
{
public:
	void setObjs(RigidBody * o1, RigidBody * o2);
	RigidBody *obj1;
	RigidBody *obj2;
};
