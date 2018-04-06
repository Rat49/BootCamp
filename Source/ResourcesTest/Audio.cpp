#include "Audio.h"

Audio::Audio(std::string id, std::string name):Resourse(id, name)
{
	
}

void Audio::load()
{
	audio.openFromFile(Audio::full_name);
}

void Audio::unload()
{
	audio.~Music();
}

//sf::Music const Audio::getStaff()
//{
//
//}

Audio::~Audio()
{
}
