#pragma once
#include "Resourse.h"
#include "Picture.h"
class ResourseManager
{
public:
	ResourseManager();
	void parseInitFile(std::string path);
	Resourse getResourse(int id);
	void releaseResourse(int id);
	~ResourseManager();

private:
//	void addResourse(Resourse * res);
	void releaseMemory();
	std::map<std::string, Resourse*> resources;	
	enum res_type {Picture_type, Audio_type, Unknown_type};

};

