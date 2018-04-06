#pragma once
#include "stdafx.h"

class FirstEvent : public Event
{
private:
	static int ID;
public:
	FirstEvent();
	virtual ~FirstEvent();
	virtual int getID() override;
};