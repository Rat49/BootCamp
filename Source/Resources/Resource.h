#pragma once
#include <string>

class Resource
{
public:
	
	Resource(const std::string& id, const std::string& fullName);
	void IncRefCounter();
	void DecRefCounter();
	unsigned int GetRefCounter() const;
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual ~Resource() = 0 {};

	std::string _fullName;

private:
	unsigned int _refCounter;	
	std::string _ID;
};
