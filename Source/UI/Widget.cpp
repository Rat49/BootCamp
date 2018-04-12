#include "Widget.h"



Widget::Widget(const std::string & name, sf::Vector2f position) :
	_owner(nullptr),
	_name(name),
	_position(position),
	_scale(1,1)
{

}


sf::Vector2f Widget::GetPosition() const
{
	return _position;
}

void Widget::SetScale(sf::Vector2f scale)
{
	_scale = scale;
}

void Widget::SetPosition(float x, float y)
{
	_position = sf::Vector2f(x, y);
}

sf::Vector2f Widget::GetScale() const
{
	return _scale;
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

void Widget::Update()
{
	_position.x = _position.x*_scale.x;
	_position.y = _position.y*_scale.y;
	this->UpdateControl();
}

Widget::~Widget()
{
}
