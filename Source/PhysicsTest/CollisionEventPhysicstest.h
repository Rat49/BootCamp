#pragma once
#include "EventSystem.h"
#include "Physics.h"
class CollisionEventPhysicstest : public Event
{
public:
	CollisionEventPhysicstest();
	virtual ~CollisionEventPhysicstest();
	 void setObjs(RigidBody&, RigidBody&);
//private:
	RigidBody obj1, obj2;
};
