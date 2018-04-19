#pragma once
#include "Drawable.h"

class drawableManager 
{
public:
	std::vector<Drawable*> _drawableObjects;

	void SortDrawableVector();
	void DrawScene(sf::RenderWindow& window);
};
