#pragma once
#include <string>

class Resource
{
public:
	
	Resource(const std::string& id, const std::string& fullName);
	virtual void IncRefCounter();
	virtual void DecRefCounter();
	virtual int GetRefCounter();
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual ~Resource() = 0;

	std::string fullName;

private:
	unsigned int refCounter;	
	std::string ID;
};
