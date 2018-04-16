#include "ResourceManager.h"


ResourceManager::ResourceManager()
{
	std::multimap<std::string, std::string> _settingsForGirl;
	_settingsForGirl.insert(std::make_pair("Width", "110"));
	_settingsForGirl.insert(std::make_pair("Height", "151"));
	_settingsForGirl.insert(std::make_pair("FrameCount", "27"));
	_settingsForGirl.insert(std::make_pair("AnimationTime", "28"));
	_settingsForGirl.insert(std::make_pair("Color", "150 2 2"));
	_settingsForGirl.insert(std::make_pair("Color", "255 255 255"));
	_settingsForGirl.insert(std::make_pair("Color", "0 0 0"));

	std::multimap<std::string, std::string> _settingsForCat;
	_settingsForCat.insert(std::make_pair("Width", "512"));
	_settingsForCat.insert(std::make_pair("Height", "256"));
	_settingsForCat.insert(std::make_pair("FrameCount", "8"));
	_settingsForCat.insert(std::make_pair("AnimationTime", "8"));

	std::multimap<std::string, std::string> _settingsForFire;
	_settingsForFire.insert(std::make_pair("Width", "192"));
	_settingsForFire.insert(std::make_pair("Height", "192"));
	_settingsForFire.insert(std::make_pair("FrameCount", "12"));
	_settingsForFire.insert(std::make_pair("AnimationTime", "12"));

	std::multimap<std::string, std::string> _settingsForSpace;
	_settingsForSpace.insert(std::make_pair("Width", "500"));
	_settingsForSpace.insert(std::make_pair("Height", "375"));
	_settingsForSpace.insert(std::make_pair("FrameCount", "1"));
	_settingsForSpace.insert(std::make_pair("AnimationTime", "60"));

	_resources.insert(std::pair<std::string, Resource*>
		("piupiu", new AudioResource("piupiu", "Resources\\audio\\piupiu.wav")));
	_resources.insert(std::pair<std::string, Resource*>
		("booom", new AudioResource("booom", "Resources\\audio\\booom.wav")));
	_resources.insert(std::pair<std::string, Resource*>
		("asteroid", new PictureResource("asteroid", "Resources\\graphics\\screen.png")));
	_resources.insert(std::pair<std::string, Resource*>
		("smallasteroid", new PictureResource("smallasteroid", "Resources\\graphics\\smallasteroid.png")));
	_resources.insert(std::pair<std::string, Resource*>
		("girl", new ImageSequenceResource("girl", "Resources\\graphics\\girl.png", _settingsForGirl)));
	_resources.insert(std::pair<std::string, Resource*>
		("cat", new ImageSequenceResource("cat", "Resources\\graphics\\cat.png", _settingsForCat)));
	_resources.insert(std::pair<std::string, Resource*>
		("fire", new ImageSequenceResource("fire", "Resources\\graphics\\fire.png", _settingsForFire)));
	_resources.insert(std::pair<std::string, Resource*>
		("space", new ImageSequenceResource("space", "Resources\\graphics\\universe.jpg", _settingsForSpace)));
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
