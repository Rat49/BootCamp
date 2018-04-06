#pragma once
#include "Resourse.h"
#include <string>
#include <map>
class ResourseManager
{
public:
	ResourseManager();

	Resourse* GetResourse(std::string key);
	void ReleaseResourse(std::string key);
	void ReleaseMemory();
	~ResourseManager();

private:
	std::map<std::string, Resourse*> resourses;

	
};

