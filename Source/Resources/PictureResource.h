#pragma once
#include "Resource.h"
#include <SFML\Graphics.hpp>
class PictureResource :
	public Resource
{
public:
	PictureResource(const std::string& id,  const std::string& fullName);

	void Load();
	void Unload();
	sf::Image Get();

	~PictureResource();
private:
	sf::Image* resource;
};

