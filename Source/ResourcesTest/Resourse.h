#pragma once
#include <string>
class Resourse
{
public:
	enum resourseType {PictureType, AudioType};
	
	Resourse(std::string id, std::string fullName, resourseType type);
	void IncRc();
	void DecRc();
	int GetRc();
	virtual bool Load();
	virtual bool Unload();
	virtual ~Resourse();
	std::string fullName;
	resourseType type;

private:
	unsigned int refCounter;	
	std::string ID;
};
