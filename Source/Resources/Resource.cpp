#include "Resource.h"


Resource::Resource(const std::string& id, const std::string& fullName):_ID(id), _fullName(fullName), _refCounter(0)
{
}

void Resource::IncRefCounter()
{
	++_refCounter;
}

void Resource::DecRefCounter()
{
	--_refCounter;
}

int Resource::GetRefCounter()
{
	return _refCounter;
}

