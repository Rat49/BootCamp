#include "DrawableManager.h"

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

void DrawableManager::DrawScene(sf::RenderWindow& window) 
{
	SortDrawableVector();

	for(auto drawableObject : _drawableObjects)
	{
		drawableObject->Draw(window);
	}
}

void DrawableManager::AddDrawableObject(Drawable* object)
{
	_drawableObjects.emplace_back(object);
	SortDrawableVector();
}

void DrawableManager::RemoveDrawableObject(Drawable* object)
{
	auto deletedObject = std::find(_drawableObjects.begin(), _drawableObjects.end(), object);
	if (deletedObject != _drawableObjects.cend())
	{
		_drawableObjects.erase(std::find(_drawableObjects.begin(), _drawableObjects.end(), object));
	}
	SortDrawableVector();
}
