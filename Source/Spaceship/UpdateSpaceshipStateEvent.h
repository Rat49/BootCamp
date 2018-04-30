#pragma once
#include "Event.h"

class UpdateSpaceshipStateEvent:
	public  Event
{
public:
	UpdateSpaceshipStateEvent(const unsigned int HP, const unsigned int countLife, const unsigned int maxCountLife) :
		  _HP(HP)
		, _countLife(countLife)
		, _maxCountLife(maxCountLife)
	{}

	const unsigned int _HP;
	const unsigned int _maxCountLife;
	const unsigned int _countLife;
};