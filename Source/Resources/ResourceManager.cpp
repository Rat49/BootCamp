#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	/*ConfigManager configManager = new ConfigManager();

	for (const auto& key : configManager.getCategory("Audio").getKeys())
	{
		Resource* resource = new Audio(key, key->GetValue());
		resources.insert(std::pair(key, resource));
	}*/

	resources.insert(std::pair<std::string, Resource*>
		("piupiu", new AudioResource("piupiu", "Resources\\audio\\piupiu.wav")));
	resources.insert(std::pair<std::string, Resource*>
		("booom", new AudioResource("booom", "Resources\\audio\\booom.wav")));
	resources.insert(std::pair<std::string, Resource*>
		("asteroid", new PictureResource("asteroid", "Resources\\graphics\\aster.bmp")));
	resources.insert(std::pair<std::string, Resource*>
		("smallasteroid", new PictureResource("smallasteroid", "Resources\\graphics\\smallasteroid.png")));

}

Resource* ResourceManager::GetGeneralResource(const std::string& key)
{
	auto iter = resources.find(key);

	assert(iter != resources.end() && "Resource not found");

	Resource* resource = iter->second;
	if (resource->GetRefCounter() != 0)
	{
		resource->IncRefCounter();
	}
	else
	{
		resource->Load();
		resource->IncRefCounter();
	}
	return resource;

}

void ResourceManager::ReleaseResource(const std::string& key)
{
	auto iter = resources.find(key);

	assert(iter != resources.end() && "Resource not found");
	assert(iter->second->GetRefCounter() != 0 && "Resource already released");

	iter->second->DecRefCounter();

}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::ReleaseAllResources()
{
	for (auto& i : resources) 
	{
		assert(i.second->GetRefCounter() == 0 && "Resource reference still exist");

		i.second->Unload();
	}
}
