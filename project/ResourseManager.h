#pragma once
#include "Resourse.h"

class ResourseManager
{
public:
	ResourseManager();

	Resourse* GetResourse(std::string key);
	void ReleaseResourse(std::string key);
	~ResourseManager();

private:
	std::map<std::string, Resourse*> resourses;

	void ReleaseMemory();
	
};

