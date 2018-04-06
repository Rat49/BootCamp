#pragma once
#include "Resourse.h"
#include <string>
#include <map>
class ResourseManager
{
public:
	ResourseManager();
	std::map<std::string, Resourse*> resourses;
	enum res_type { Picture_type, Audio_type, Unknown_type };

	Resourse* getResourse(std::string key);
	void releaseResourse(std::string key);
	~ResourseManager();

private:
	void releaseMemory();
	
};

