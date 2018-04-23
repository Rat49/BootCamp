#pragma once
#include "EventSystem.h"

class CollisionEvent : public Event
{
public:
	CollisionEvent();
	virtual ~CollisionEvent();
	void setObjs(RigidBody&, RigidBody&);
//private:
	RigidBody obj1, obj2;
};
