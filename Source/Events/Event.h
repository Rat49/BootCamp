#pragma once
class Event
{
public:
	virtual int getID() = 0;

	virtual ~Event();
};