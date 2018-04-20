#include "Object.h"

sf::Vector2u Object::GetSizeWindow() const
{
	return _sizeSpace;
}


void Object::Add()
{
	DrawableManager::getInstance()._drawableObjects.push_back(this);
	DrawableManager::getInstance().SortDrawableVector();
}

int Object::GetZOrder() const
{
	return _zOrder;
}
