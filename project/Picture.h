#pragma once
#include "Resourse.h"
class Picture :
	public Resourse
{
public:
	Picture(int id, char * name);
	sf::Image getStaff();
	~Picture();
private:
	sf::Image img;
};

