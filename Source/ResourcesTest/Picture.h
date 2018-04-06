#pragma once
#include "Resourse.h"
#include <SFML\Graphics.hpp>
class Picture :
	public Resourse
{
public:
	Picture(std::string id, std::string full_name);

	void load();
	void unload();
	sf::Image getStaff();

	~Picture();
private:
	sf::Image img;
};

