#include "ResourseManager.h"

#include "Audio.h"
#include "Picture.h"
#include "Resourse.h"
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

Resourse* ResourseManager::GetResourse(std::string key)
{
	if (resourses.find(key) != resourses.end())
	{
		if (resourses[key]->GetRc() != 0)
		{
			ResourseManager::resourses[key]->IncRc();
		}
		else
		{
			resourses[key]->Load();
			ResourseManager::resourses[key]->IncRc();
		}
		return resourses[key];
	}
	else
		return nullptr;
}

void ResourseManager::ReleaseResourse(std::string key)
{
	if (resourses.find(key) != resourses.end() && resourses[key]->GetRc() != 0)
	{
		resourses[key]->DecRc();
	}	
}

ResourseManager::~ResourseManager()
{
}

void ResourseManager::ReleaseMemory()
{
	for (auto i : resourses) 
	{
		if (i.second->GetRc() == 0)
		{
			i.second->Unload();
		}
	}
}
