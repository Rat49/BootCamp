#pragma once
#include "Resource.h"
#include <SFML\Graphics.hpp>
class Picture :
	public Resource
{
public:
	Picture(std::string id, std::string full_name);

	bool Load();
	bool Unload();
	sf::Image GetStaff();

	~Picture();
private:
	sf::Image img;
};

