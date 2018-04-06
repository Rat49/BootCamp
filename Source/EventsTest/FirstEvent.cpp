#include "FirstEvent.h"

int FirstEvent::ID = 0;
FirstEvent::FirstEvent()
{
}
FirstEvent::~FirstEvent()
{
}
int FirstEvent::getID()
{
	if (ID == 0)
	{
		ID = ++EventIDStore::eventID;
	}
	return ID;
}