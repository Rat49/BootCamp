#pragma once
#include <cassert>
#include <SFML\Graphics.hpp>
#include "Resource.h"

class TextureResource : public Resource
{
public:
	TextureResource(const std::string& id, const std::string& fullName);
	~TextureResource() override;

	void Load() override;
	void Unload() override;

	sf::Texture& Get();

private:
	sf::Texture* _resource;
};