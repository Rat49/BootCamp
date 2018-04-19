#include "DrawableManager.h"

DrawableManager::DrawableManager()
{
}

DrawableManager::~DrawableManager()
{
}

DrawableManager& DrawableManager::getInstance()
{
	static DrawableManager instance;
	return instance;
}

void DrawableManager::SortDrawableVector()
{
	std::vector<Drawable*>::iterator firstObject = _drawableObjects.begin();
	std::vector<Drawable*>::iterator lastObject = _drawableObjects.begin();
	std::size_t lastSortedObject = 2;
	std::advance(lastObject, std::min(lastSortedObject, _drawableObjects.size()));
	
	std::partial_sort(firstObject, lastObject, _drawableObjects.end(), [](const Drawable* lhs, const Drawable* rhs)
	{
		return lhs->GetZOrder() < rhs->GetZOrder();
	}
	);
}

void DrawableManager::DrawScene(sf::RenderWindow & window) 
{
	SortDrawableVector();

	for (auto drawableObject = _drawableObjects.begin(); drawableObject != _drawableObjects.end(); ++drawableObject)
	{
		(*drawableObject)->Draw(window);
	}
}
