#pragma once
#include "Event.h"
class CollisionEventForTest : public Event
{
public:
	RigidBody* _rigidBody1;
	RigidBody* _rigidBody2;
};