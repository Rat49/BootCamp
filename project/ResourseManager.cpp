#include "ResourseManager.h"

#include "Audio.h"
#include "Picture.h"
#include "Resourse.h"

#include "stdafx.h"

ResourseManager::ResourseManager()
{
	/*ConfigManager configManager = new ConfigManager();

	for (const auto &key : configManager.getCategory("Audio").getKeys())
	{
		Resourse* resource = new Audio(key, key->GetValue());
		resources.insert(std::pair(key, resource));
	}*/

	resourses.insert(std::pair<std::string, Resourse*>
		("piupiu", new Audio("piupiu", "C:\Projects\BootCamp\project\audio\piupiu.wav")));
	resourses.insert(std::pair<std::string, Resourse*>
		("booom", new Audio("booom", "C:\Projects\BootCamp\project\audio\booom.wav")));
	resourses.insert(std::pair<std::string, Resourse*>
		("asteroid", new Picture("asteroid", "C:\Projects\BootCamp\project\graphics\asteroid.png")));
	resourses.insert(std::pair<std::string, Resourse*>
		("smallasteroid", new Picture("smallasteroid", "C:\Projects\BootCamp\project\graphics\smallasteroid.bmp")));

}

Resourse* ResourseManager::getResourse(std::string key)
{
	if (resourses[key]->getRc() != 0)
	{
		ResourseManager::resourses[key]->incRc();
	}
	else
	{
		resourses[key]->load();
		ResourseManager::resourses[key]->incRc();
	}
	return resourses[key];
}

void ResourseManager::releaseResourse(std::string key)
{
	if (resourses[key]->getRc() != 0)
	{
		resourses[key]->decRc();
	}	
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
