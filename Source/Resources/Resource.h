#pragma once
#include <string>

class Resource
{
public:
	
	Resource(std::string id, std::string fullName);
	void IncRc();
	void DecRc();
	int GetRc();
	virtual bool Load();
	virtual bool Unload();
	virtual ~Resource();
	std::string fullName;

private:
	unsigned int refCounter;	
	std::string ID;
};
