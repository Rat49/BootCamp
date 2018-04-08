#include "Resource.h"


Resource::Resource(const std::string& id, const std::string& fullName):ID(id), fullName(fullName), refCounter(0)
{
}

void Resource::IncRefCounter()
{
	++refCounter;
}

void Resource::DecRefCounter()
{
	--refCounter;
}

int Resource::GetRefCounter()
{
	return refCounter;
}

