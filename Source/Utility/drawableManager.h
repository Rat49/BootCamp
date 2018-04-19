#pragma once
#pragma once
#include "Drawable.h"

class DrawableManager
{
public:
	static std::vector<Drawable*> _drawableObjects;

	void SortDrawableVector();
	void DrawScene(sf::RenderWindow& window);
};

