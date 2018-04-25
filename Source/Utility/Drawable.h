#pragma once
#include <SFML\Graphics\RenderWindow.hpp>

class Drawable 
{
public:
	virtual void AddToDrawableManager() = 0;
	virtual int GetZOrder() const = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

protected:
	int _zOrder;
};