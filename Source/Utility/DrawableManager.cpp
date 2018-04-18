#include "drawableManager.h"


void drawableManager::SortDrawableVector()
{
	//_drawableObjects std::partial_sort
}

void drawableManager::DrawScene(sf::RenderWindow & window) 
{
	SortDrawableVector();

	for (auto drawableObject = _drawableObjects.cbegin(); drawableObject != _drawableObjects.cend(); ++drawableObject)
	{
		(*drawableObject)->Draw(window);
	}
}
