#include "AudioResource.h"
#include <cassert>

AudioResource::AudioResource(const std::string& id, const std::string& name):Resource(id, name), resource(nullptr)
{
	
}

void AudioResource::Load()
{
	resource = new sf::Music();
	bool isLoadSuccess = resource->openFromFile(fullName);
	assert(isLoadSuccess && "Resource can not be loaded");
}

void AudioResource::Unload()
{
	delete(resource);
}

sf::Music& AudioResource::Get()
{
	assert(resource != nullptr && "Resource not loaded");
	return *resource;
}

AudioResource::~AudioResource()
{
}
