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
	std::sort(_drawableObjects.begin(), _drawableObjects.end(), [](const Drawable* lhs, const Drawable* rhs)
	{
		return lhs->GetZOrder() > rhs->GetZOrder();
	}
	);
}

void DrawableManager::DrawScene(sf::RenderWindow & window) 
{
	SortDrawableVector();

	for (auto drawableObject = _drawableObjects.cbegin(); drawableObject != _drawableObjects.cend(); ++drawableObject)
	{
		(*drawableObject)->Draw(window);
	}
}
