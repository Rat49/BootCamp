#pragma once
#include "EventTypes.h"

class Event
{
public:
	EventID_t ID;
	virtual ~Event() = 0 {};
};