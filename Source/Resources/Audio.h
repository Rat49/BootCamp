#pragma once
#include "Resource.h"
#include <SFML\Audio.hpp>
class Audio :
	public Resource
{
public:
	Audio(std::string id, std::string full_name);

	bool Load();
	bool Unload();
	sf::Music& GetStaff();

	~Audio();	

private:
	sf::Music audio;
};

