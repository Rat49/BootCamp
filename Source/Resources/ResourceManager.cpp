#include "ResourceManager.h"

#include "Audio.h"
#include "Picture.h"
#include "Resource.h"
ResourceManager::ResourceManager()
{
	/*ConfigManager configManager = new ConfigManager();

	for (const auto &key : configManager.getCategory("Audio").getKeys())
	{
		Resource* resource = new Audio(key, key->GetValue());
		resources.insert(std::pair(key, resource));
	}*/

	resources.insert(std::pair<std::string, Resource*>
		("piupiu", new Audio("piupiu", "..\resources\audio\piupiu.wav")));
	resources.insert(std::pair<std::string, Resource*>
		("booom", new Audio("booom", "..\resources\audio\booom.wav")));
	resources.insert(std::pair<std::string, Resource*>
		("asteroid", new Picture("asteroid", "..\resources\graphics\aster.png")));
	resources.insert(std::pair<std::string, Resource*>
		("smallasteroid", new Picture("smallasteroid", "..\resources\graphics\smallasteroid.bmp")));

}

Resource* ResourceManager::GetGeneralResource(std::string key)
{
	if (resources.find(key) != resources.end())
	{
		if (resources[key]->GetRc() != 0)
		{
			ResourceManager::resources[key]->IncRc();
		}
		else
		{
			resources[key]->Load();
			ResourceManager::resources[key]->IncRc();
		}
		return resources[key];
	}
	else
		return nullptr;
}

void ResourceManager::ReleaseResource(std::string key)
{
	if (resources.find(key) != resources.end() && resources[key]->GetRc() != 0)
	{
		resources[key]->DecRc();
	}	
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::ReleaseMemory()
{
	for (auto i : resources) 
	{
		if (i.second->GetRc() == 0)
		{
			i.second->Unload();
		}
	}
}
