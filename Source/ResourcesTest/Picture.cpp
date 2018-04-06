#include "Picture.h"

Picture::Picture(std::string id, std::string name):Resourse(id, name)
{
}

bool Picture::Load()
{
	return img.loadFromFile(Picture::fullName);
}

bool Picture::Unload()
{
	img.~Image();
	return true;
}


sf::Image Picture::GetStaff()
{
	return img;
}


Picture::~Picture()
{

}
