#include "Object.h"

void Object::DrawInWindow(const sf::Drawable & obj)
{
	_window->draw(obj);
}

sf::Vector2u Object::GetSizeWindow() const
{
	return _window->getSize();
}
void Object::SetWindowOneTime(sf::RenderWindow & window)
{
	if (_window == nullptr)
	{
		_window = &window;
	}
}
