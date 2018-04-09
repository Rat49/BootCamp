#include "PictureResource.h"
#include <cassert>

PictureResource::PictureResource(const std::string& id, const std::string& name):Resource(id, name), _resource(nullptr)
{
}

void PictureResource::Load() 
{
	_resource = new sf::Image();
	bool isLoadSuccess = _resource->loadFromFile(_fullName);
	if (!isLoadSuccess)
	{
		_resource = nullptr;
	}
	assert(isLoadSuccess && "Resource can not be loaded");
}

void PictureResource::Unload()
{
	delete(_resource);
	_resource = nullptr;
}

sf::Image& PictureResource::Get()
{
	assert(GetRefCounter() != 0 && "Resource references not found");
	return *_resource;
}


PictureResource::~PictureResource()
{
	
}
