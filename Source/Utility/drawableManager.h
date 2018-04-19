#pragma once
#include "Drawable.h"
#include <algorithm>

class DrawableManager
{
private:
	DrawableManager(DrawableManager const&) = delete;

	DrawableManager& operator= (DrawableManager const&) = delete;

	DrawableManager();

	~DrawableManager();
public:
	std::vector<Drawable*> _drawableObjects;

	static DrawableManager& getInstance();
	void SortDrawableVector();
	void DrawScene(sf::RenderWindow& window);
};