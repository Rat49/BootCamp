#include "TextureResource.h"

TextureResource::TextureResource(const std::string& id, const std::string& name)
	: Resource(id, name)
	, _resource(nullptr)
{
}

TextureResource::~TextureResource()
{
}

void TextureResource::Load()
{
	IncRefCounter();
	_resource = new sf::Texture();
	bool isLoadSuccess = _resource->loadFromFile(_fullName);
	if (!isLoadSuccess)
	{
		delete _resource;
		_resource = nullptr;
	}

	assert(isLoadSuccess && "Resource can not be loaded");
}

void TextureResource::Unload()
{
	delete _resource;
	_resource = nullptr;
}

sf::Texture& TextureResource::Get()
{
	assert(GetRefCounter() != 0 && "Resource references not found");
	return *_resource;
}
