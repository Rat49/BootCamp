#pragma once
#include "Resourse.h"

class Audio :
	public Resourse
{
public:
	Audio(std::string id, std::string fullName);	

	bool Load();
	bool Unload();
	sf::Music& GetStaff();

	~Audio();	

private:
	sf::Music audio;
};

