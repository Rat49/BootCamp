#include "Resource.h"


Resource::Resource(std::string id, std::string fullName):ID(id), fullName(fullName), refCounter(0)
{
}

void Resource::IncRc()
{
	++refCounter;
}

void Resource::DecRc()
{
	--refCounter;
}

int Resource::GetRc()
{
	return refCounter;
}

bool Resource::Load()
{
	return false;
}

bool Resource::Unload()
{
	return false;
}


Resource::~Resource()
{
	Resource::refCounter = 0;
}
