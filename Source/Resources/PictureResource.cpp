#include "PictureResource.h"
#include <cassert>

PictureResource::PictureResource(const std::string& id, const std::string& name):Resource(id, name), resource(nullptr)
{
}

void PictureResource::Load()
{
	resource = new sf::Image();
	bool isLoadSuccess = resource->loadFromFile(fullName);

	if (!isLoadSuccess)
	{
		resource = nullptr;
	}
	assert(isLoadSuccess && "Resource can not be loaded");
}

void PictureResource::Unload()
{

}

sf::Image PictureResource::Get()
{
	assert(resource != nullptr && "Resource not loaded");
	return *resource;
}


PictureResource::~PictureResource()
{
	
}
