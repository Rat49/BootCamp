#pragma once
#include "Resourse.h"
#include <SFML\Audio.hpp>
class Audio :
	public Resourse
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

