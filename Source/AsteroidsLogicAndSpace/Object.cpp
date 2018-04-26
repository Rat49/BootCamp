#include "Object.h"

sf::Vector2u Object::GetSizeWindow() const
{
	return _sizeSpace;
}

void Object::AddToDrawableManager()
{
	DrawableManager::getInstance().AddDrawableObject(this);
}

void Object::Remove()
{
	DrawableManager::getInstance().RemoveDrawableObject(this);
}

int Object::GetZOrder() const
{
	return _zOrder;
}
