#include "Widget.h"



Widget::Widget(const std::string & name, sf::RenderWindow& caller) :
	_owner(caller),
	_name(name)
{
}


sf::RenderWindow & Widget::GetOwner()
{
	return _owner;
}


Widget::~Widget()
{
}
