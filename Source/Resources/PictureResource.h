#pragma once
#include "Resource.h"
#include <SFML\Graphics.hpp>
class PictureResource :
	public Resource
{
public:
	PictureResource(const std::string& id,  const std::string& fullName);

	void Load() override;
	void Unload() override;
	sf::Image& Get();

	~PictureResource() override;
private:
	sf::Image* _resource;
};

