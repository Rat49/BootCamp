#pragma once
#include "Resourse.h"
#include <SFML\Audio.hpp>
class Audio :
	public Resourse
{
public:
	Audio(std::string id, std::string full_name);

	void load();
	void unload();
	//sf::Music const getStaff();

	~Audio();	

private:
	sf::Music audio;
};

