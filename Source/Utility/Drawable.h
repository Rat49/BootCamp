#pragma once
#include "SFML\Graphics.hpp"

class Drawable 
{
protected:
	int _zOrder;
public:
	virtual void Add() = 0; 
	virtual int GetZOrder() const = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};