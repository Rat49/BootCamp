#include "Audio.h"

Audio::Audio(std::string id, std::string name):Resourse(id, name)
{
	
}

bool Audio::Load()
{
	return audio.openFromFile(Audio::fullName);
}

bool Audio::Unload()
{
	audio.~Music();
	return true;
}

sf::Music& Audio::GetStaff()
{
	return audio;
}

Audio::~Audio()
{
}
