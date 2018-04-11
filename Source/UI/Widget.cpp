#include "Widget.h"



Widget::Widget(const std::string & name, sf::Vector2f position, sf::RenderWindow& caller) :
	_owner(caller),
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

sf::RenderWindow & Widget::GetOwner()
{
	return _owner;
}


Widget::~Widget()
{
}
