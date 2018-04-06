#include "stdafx.h"
#include "Resourse.h"


Resourse::Resourse(std::string id, std::string fullName):ID(id), fullName(fullName), refCounter(0) 
{
}

void Resourse::IncRc()
{
	++refCounter;
}

void Resourse::DecRc()
{
	--refCounter;
}

int Resourse::GetRc()
{
	return refCounter;
}

bool Resourse::Load()
{
	
}

bool Resourse::Unload()
{
	
}


Resourse::~Resourse()
{
	Resourse::refCounter = 0;
}
