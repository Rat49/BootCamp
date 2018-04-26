#include "ResourceManager.h"
#include "AudioResource.h"
#include "ImageSequenceResource.h"
#include "PictureResource.h"
#include "Resource.h"
#include "TextureResource.h"

ResourceManager::ResourceManager(const std::map<std::string, std::multimap<const std::string, const std::string>>& resourceConfig)
{
	const std::multimap<const std::string, const std::string>& audioResource = resourceConfig.find("AudioResource")->second;
	for (auto audio : audioResource)
	{
		_resources.insert(std::pair<std::string, Resource*>
		(audio.first, new AudioResource(audio.first, audio.second)));
	}
	const std::multimap<const std::string, const std::string>& pictureResource = resourceConfig.find("PictureResource")->second;
	for (auto picture : pictureResource)
	{
		_resources.insert(std::pair<std::string, Resource*>
			(picture.first, new PictureResource(picture.first, picture.second)));
	}
	for (const auto imageSequence : resourceConfig.find("ImageSequenceResource")->second)
	{
		_resources.insert(std::pair<std::string, Resource*>
				(imageSequence.first, new ImageSequenceResource(imageSequence.first, 
					imageSequence.second, 
					resourceConfig.find("ImageSequenceResource." + imageSequence.first)->second)));
	}
	const std::multimap<const std::string, const std::string>& textureResource = resourceConfig.find("TextureResource")->second;
	for (auto texture : textureResource)
	{
		_resources.insert(std::pair<std::string, Resource*>
			(texture.first, new TextureResource(texture.first, texture.second)));
	}
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
