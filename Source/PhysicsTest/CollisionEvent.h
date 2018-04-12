#pragma once
#include "EventSystem.h"

class CollisionEvent : public Event
{
public:
	CollisionEvent();
	virtual ~CollisionEvent();
};