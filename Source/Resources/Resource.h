#pragma once
#include <string>

class Resource
{
public:
	
	Resource(const std::string& id, const std::string& fullName);
	void IncRefCounter();
	void DecRefCounter();
	int GetRefCounter();
	virtual void Load() = 0;
	virtual void Unload() = 0;
	~Resource();

	std::string fullName;

private:
	unsigned int refCounter;	
	std::string ID;
};
