#include "drawableManager.h"


void DrawableManager::SortDrawableVector()
{
	//_drawableObjects std::partial_sort
}

void DrawableManager::DrawScene(sf::RenderWindow & window) 
{
	SortDrawableVector();

	for (auto drawableObject = _drawableObjects.cbegin(); drawableObject != _drawableObjects.cend(); ++drawableObject)
	{
		(*drawableObject)->Draw(window);
	}
}
