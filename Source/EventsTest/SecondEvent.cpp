#include "stdafx.h"

int SecondEvent::ID = 0;
SecondEvent::SecondEvent()
{
}
SecondEvent::~SecondEvent()
{
}
int SecondEvent::getID()
{
	if (ID == 0)
	{
		ID = ++EventIDStore::eventID;
	}
	return ID;
}