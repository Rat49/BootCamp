#include "Picture.h"

Picture::Picture(std::string id, std::string name):Resourse(id, name)
{
}

void Picture::load()
{
	img.loadFromFile(Picture::full_name);
}

void Picture::unload()
{
	img.~Image();
}


sf::Image Picture::getStaff()
{
	return img;
}


Picture::~Picture()
{

}
