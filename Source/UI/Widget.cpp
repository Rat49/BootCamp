#include "Widget.h"



Widget::Widget(const std::string & name, sf::Vector2f position) :
	_owner(nullptr),
	_name(name),
	_position(position)
{

}


sf::Vector2f Widget::GetPosition() const
{
	return _position;
}

void Widget::SetPosition(float x, float y)
{
	_position = sf::Vector2f(x, y);
}

void Widget::AddOwner(sf::RenderWindow * host)
{
	if (_owner == nullptr)
	{
		_owner = host;
	}
	else
	{
		//This is place for log
	}
}

Widget::~Widget()
{
}
