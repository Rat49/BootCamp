#pragma once
#include "Resourse.h"
#include <SFML\Graphics.hpp>
class Picture :
	public Resourse
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

