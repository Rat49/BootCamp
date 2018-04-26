#pragma once
#include <SFML\Audio.hpp>
#include "Resource.h"

class AudioResource : public Resource
{
public:
	AudioResource(const std::string& id, const std::string& fullName);
	~AudioResource() override;

	void Load() override;
	void Unload() override;
	sf::Music& Get();

private:
	sf::Music* _resource;
};

