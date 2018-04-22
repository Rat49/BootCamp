#pragma once
#include "SFML\Graphics.hpp"

struct WindowResolution
{
	static int _W;
	static int _H;

	static void SetResolution(sf::RenderWindow& window);
};