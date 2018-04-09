#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	

	_resources.insert(std::pair<std::string, Resource*>
		("piupiu", new AudioResource("piupiu", "Resources\\audio\\piupiu.wav")));
	_resources.insert(std::pair<std::string, Resource*>
		("booom", new AudioResource("booom", "Resources\\audio\\booom.wav")));
	_resources.insert(std::pair<std::string, Resource*>
		("asteroid", new PictureResource("asteroid", "Resources\\graphics\\aster.bmp")));
	_resources.insert(std::pair<std::string, Resource*>
		("smallasteroid", new PictureResource("smallasteroid", "Resources\\graphics\\smallasteroid.png")));

}

Resource* ResourceManager::GetGeneralResource(const std::string& key)
{
	auto iter = _resources.find(key);

	assert(iter != _resources.end() && "Resource not found");

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
	auto iter = _resources.find(key);

	assert(iter != _resources.end() && "Resource not found");
	assert(iter->second->GetRefCounter() != 0 && "Resource already released");

	iter->second->DecRefCounter();
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::ReleaseAllResources()
{
	for (auto& i : _resources) 
	{
		assert(i.second->GetRefCounter() == 0 && "Resource reference still exists");

		i.second->Unload();
	}
}
