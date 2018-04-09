#pragma once
#include <SFML\Audio.hpp>
#include "Resource.h"

class AudioResource :
	public Resource
{
public:
	AudioResource(const std::string& id, const std::string& fullName);

	void Load() override;
	void Unload() override;
	sf::Music& Get();

	~AudioResource() override;

private:
	sf::Music* _resource;
};

