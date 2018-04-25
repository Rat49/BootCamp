#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class Drawable 
{
protected:
	int _zOrder;
public:
	virtual void AddToDrawableManager() = 0; 
	virtual int GetZOrder() const = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};