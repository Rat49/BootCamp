#include "stdafx.h"
#include "ResourseManager.h"
#include "Resourse.h"
#include "Audio.h"
#include "Picture.h"

ResourseManager::ResourseManager()
{
	

}

Resourse ResourseManager::getResourse(std::string key, std::string path, ResourseManager::res_type type)
{
	if (ResourseManager::resourses.find(key) != resourses.end())
	{
		ResourseManager::resourses[key]->incRc();
	}
	else
	{
		Resourse* resourse;

		switch (type)
		{
		case ResourseManager::Audio_type:
			*resourse = Audio(key, path);
			break;
		case ResourseManager::Picture_type:
			*resourse = Picture(key, path);
			break;
		default:
			break;
		}

		resourse->load();
		ResourseManager::resourses.insert(std::pair<std::string, Resourse*>(key, resourse));
		ResourseManager::resourses[key]->incRc();
	}
	return *resourses[key];
}

void ResourseManager::releaseResourse(std::string key)
{
	if (resourses[key]->getRc == 0)
	{
		return;
	}
	resourses[key]->decRc();
	
}

ResourseManager::~ResourseManager()
{
}

void ResourseManager::releaseMemory()
{
	for (auto i : resourses) 
	{
		if (i.second->getRc() == 0)
		{
			i.second->unload();
		}
	}
}
