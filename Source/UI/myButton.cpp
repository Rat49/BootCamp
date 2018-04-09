#include "myButton.h"

#include <iostream>

myButton::myButton(const float w, const float h, const float x, const float y,const sf::Window& caller) :
	_body(sf::Vector2f(w,h)),
	_owner(caller)
{
	_body.setPosition(sf::Vector2f(x, y));
}

bool myButton::isClicked()
{
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		return false;
	}
	auto cursor_pos = sf::Mouse::getPosition(_owner);
	
	float down = _body.getPosition().y;
	float up = down + _body.getSize().y;
	float left = _body.getPosition().x;
	float right = left + _body.getSize().x;

	if (!(cursor_pos.x < right && cursor_pos.x > left && cursor_pos.y < up && cursor_pos.y > down))
	{
		return false;
	}
	else
	{
		std::cout << "clicked!! ";
		return true;
	}
}


myButton::~myButton()
{
}
