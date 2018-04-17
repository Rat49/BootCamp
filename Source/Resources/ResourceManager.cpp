#include "ResourceManager.h"


ResourceManager::ResourceManager(std::map<std::string, std::vector<std::pair<std::string, std::string>>>& resourceConfig)
{
	std::multimap<std::string, std::string> _settingsForGirl;
	_settingsForGirl.insert(std::make_pair("Width", "110"));
	_settingsForGirl.insert(std::make_pair("Height", "151"));
	_settingsForGirl.insert(std::make_pair("FrameCount", "27"));
	_settingsForGirl.insert(std::make_pair("AnimationTime", "1350"));
	_settingsForGirl.insert(std::make_pair("Color", "150 2 2"));
	_settingsForGirl.insert(std::make_pair("Color", "255 255 255"));
	_settingsForGirl.insert(std::make_pair("Color", "0 0 0"));

	std::multimap<std::string, std::string> _settingsForCat;
	_settingsForCat.insert(std::make_pair("Width", "512"));
	_settingsForCat.insert(std::make_pair("Height", "256"));
	_settingsForCat.insert(std::make_pair("FrameCount", "8"));
	_settingsForCat.insert(std::make_pair("AnimationTime", "400"));

	std::multimap<std::string, std::string> _settingsForFire;
	_settingsForFire.insert(std::make_pair("Width", "192"));
	_settingsForFire.insert(std::make_pair("Height", "192"));
	_settingsForFire.insert(std::make_pair("FrameCount", "12"));
	_settingsForFire.insert(std::make_pair("AnimationTime", "600"));

	std::vector<std::pair<std::string, std::string>> audioResource = resourceConfig.find("AudioResource")->second;
	std::vector<std::pair<std::string, std::string>> pictureResource = resourceConfig.find("PictureResource")->second;
	std::vector<std::pair<std::string, std::string>> imageSequenceResource = resourceConfig.find("ImageSequenceResource")->second;

	for (auto audio : audioResource)
	{
		_resources.insert(std::pair<std::string, Resource*>
			(audio.first, new AudioResource(audio.first, audio.second)));
	}
	for (auto picture : pictureResource)
	{
		_resources.insert(std::pair<std::string, Resource*>
			(picture.first, new AudioResource(picture.first, picture.second)));
	}
	
	for (int i = 0; i < imageSequenceResource.size(); i++)
	{
		_resources.insert(std::pair<std::string, Resource*>
			(imageSequenceResource[i].first, new ImageSequenceResource(imageSequenceResource[i].first, 
				imageSequenceResource[i].second,
				resourceConfig.find("ImageSequenceResource"+ imageSequenceResource[i].first)->second)));
	}
	//_resources.insert(std::pair<std::string, Resource*>
	//	("piupiu", new AudioResource("piupiu", "Resources\\audio\\piupiu.wav")));
	//_resources.insert(std::pair<std::string, Resource*>
	//	("booom", new AudioResource("booom", "Resources\\audio\\booom.wav")));
	//_resources.insert(std::pair<std::string, Resource*>
	//	("asteroid", new PictureResource("asteroid", "Resources\\graphics\\aster.bmp")));
	//_resources.insert(std::pair<std::string, Resource*>
	//	("smallasteroid", new PictureResource("smallasteroid", "Resources\\graphics\\smallasteroid.png")));
	//_resources.insert(std::pair<std::string, Resource*>
	//	("girl", new ImageSequenceResource("girl", "Resources\\graphics\\girl.png", _settingsForGirl)));
	//_resources.insert(std::pair<std::string, Resource*>
	//	("cat", new ImageSequenceResource("cat", "Resources\\graphics\\cat.png", _settingsForCat)));
	_resources.insert(std::pair<std::string, Resource*>
		("fire", new ImageSequenceResource("fire", "Resources\\graphics\\fire.png", _settingsForFire)));
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
