#pragma once
#include "SFML\Graphics.hpp"

class Drawable
{
protected:
	int _zOrder;
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void setZOrder(int zOrder) = 0;
	virtual int getZOrder() const = 0;
};