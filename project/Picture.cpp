#include "Picture.h"
#include "stdafx.h"

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
}


sf::Image Picture::GetStaff()
{
	return img;
}


Picture::~Picture()
{

}
