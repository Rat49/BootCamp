#pragma once
#include "stdafx.h"

class SecondEvent : public Event
{
private:
	static int ID;
public:
	SecondEvent();
	virtual ~SecondEvent();
	virtual int getID() override;
}; 
