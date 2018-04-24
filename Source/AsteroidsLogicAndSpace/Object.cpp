#include "Object.h"

std::vector<Object*> Object::_allObjects;

sf::Vector2u Object::GetSizeWindow() const
{
	return _sizeSpace;
}

void Object::Add()
{
	DrawableManager::getInstance()._drawableObjects.push_back(this);
	DrawableManager::getInstance().SortDrawableVector();

	_allObjects.push_back(this);
}

void Object::Remove()
{
	std::vector<Drawable*> &drawableObjects = DrawableManager::getInstance()._drawableObjects;
	drawableObjects.erase(std::find(drawableObjects.begin(), drawableObjects.end(), this));
	DrawableManager::getInstance().SortDrawableVector();

	_allObjects.erase(std::find(_allObjects.begin(), _allObjects.end(), this));
}

int Object::GetZOrder() const
{
	return _zOrder;
}
