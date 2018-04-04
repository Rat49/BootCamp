#include "stdafx.h"
#include "Picture.h"


Picture::Picture(int id, char * name):Resourse(id, name)
{
}

sf::Image Picture::getStaff()
{
	return img;
}


Picture::~Picture()
{

}
