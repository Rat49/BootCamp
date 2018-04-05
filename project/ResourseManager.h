#pragma once
#include "Resourse.h"
#include "Picture.h"
class ResourseManager
{
private:
	enum res_type { Picture_type, Audio_type, Unknown_type };

public:
	ResourseManager();
	std::map<std::string, Resourse*> resourses;

	Resourse getResourse(std::string key, std::string path, ResourseManager::res_type type);
	void releaseResourse(std::string key);
	~ResourseManager();

private:
	void releaseMemory();
	
};

