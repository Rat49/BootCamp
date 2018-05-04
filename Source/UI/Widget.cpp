#include "Widget.h"



Widget::Widget(const std::string & name, const sf::Vector2f position,sf::RenderWindow &owner) :
	_window(owner),
	_name(name),
	_position(position),
	_scale(1,1)
{

}


sf::Vector2f Widget::GetPosition() const
{
	return _position;
}

void Widget::SetScale(const sf::Vector2f scale)
{
	_scale = scale;
}

void Widget::SetPosition(const sf::Vector2f position)
{
	_position = position;
}

sf::Vector2f Widget::GetScale() const
{
	return _scale;
}

void Widget::Resize()
{
	_position.x = _position.x*_scale.x;
	_position.y = _position.y*_scale.y;
	this->OnResize();
}

Widget::~Widget()
{
}
