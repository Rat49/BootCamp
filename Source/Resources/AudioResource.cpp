#include "AudioResource.h"
#include <cassert>

AudioResource::AudioResource(const std::string& id, const std::string& name):
	Resource(id, name), 
	_resource(nullptr)
{
	
}

void AudioResource::Load()
{
	IncRefCounter();
	_resource = new sf::Music();
	bool isLoadSuccess = _resource->openFromFile(_fullName);
	if (!isLoadSuccess)
	{
		_resource = nullptr;
	}
	assert(isLoadSuccess && "Resource can not be loaded");
}

void AudioResource::Unload()
{
	delete(_resource);
	_resource = nullptr;
}

sf::Music* AudioResource::Get()
{
	assert(GetRefCounter() != 0 && "Resource references not found");
	return _resource;
}

AudioResource::~AudioResource()
{
}
