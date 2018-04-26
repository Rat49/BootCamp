#pragma once
#include <SFML\Graphics.hpp>
#include "Resource.h"

class PictureResource : public Resource
{
public:
	PictureResource(const std::string& id,  const std::string& fullName);
	~PictureResource() override;

	void Load() override;
	void Unload() override;
	sf::Image* Get();
	
private:
	sf::Image* _resource;
};

