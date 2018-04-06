#pragma once
#include <string>
class Resourse
{
public:
	Resourse(std::string id, std::string fullName);
	void IncRc();
	void DecRc();
	int GetRc();
	virtual bool Load();
	virtual bool Unload();
	virtual ~Resourse();
	std::string fullName;
private:
	unsigned int refCounter;	
	std::string ID;
};
