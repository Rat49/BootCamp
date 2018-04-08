#pragma once
#include "Resource.h"
#include <SFML\Audio.hpp>
class AudioResource :
	public Resource
{
public:
	AudioResource(const std::string& id, const std::string& fullName);

	void Load();
	void Unload();
	sf::Music& Get();

	~AudioResource();

private:
	sf::Music* resource;
};

