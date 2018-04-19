#include "DrawableManager.h"
#include <iostream>


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
	/*std::partial_sort(_drawableObjects.begin(), _drawableObjects.begin()+2, _drawableObjects.end(), [](const Drawable* lhs, const Drawable* rhs)
	{
		return lhs->GetZOrder() < rhs->GetZOrder();
	}
	);*/
}

void DrawableManager::DrawScene(sf::RenderWindow & window) 
{
	//SortDrawableVector();

	for (auto drawableObject = _drawableObjects.begin(); drawableObject != _drawableObjects.end(); ++drawableObject)
	{
		std::cout << drawableObject->GetZOrder() << std::endl;
		drawableObject->Draw(window);
	}
}
