#pragma once
#include <SFML\Graphics.hpp>
#include "Resource.h"
#include <cassert>

class TextureResource :
	public Resource
{
public:
	TextureResource(const std::string& id, const std::string& fullName);

	void Load() override;
	void Unload() override;
	sf::Texture* Get();

	~TextureResource() override;
private:
	sf::Texture* _resource;
};