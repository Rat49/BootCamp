#include "SfmlButton.h"

#include <iostream>

SfmlButton::SfmlButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string & name) :
	
	Widget(name,pos)
{	
	_body = sf::RectangleShape(size);
	_body.setPosition(pos);
}

bool SfmlButton::IsClicked(sf::Vector2i cursor_pos) const
{
	auto tmp = _body.getGlobalBounds();
	if (!_body.getGlobalBounds().contains(static_cast<sf::Vector2f>(cursor_pos)))
	{
		return false;
	}
	else
	{
		std::cout << "clicked on " << this->_name << " ";
		return true;
	}
}

void SfmlButton::SetColor(const sf::Color & color)
{
	_body.setFillColor(color);
}

void SfmlButton::SetSize(const sf::Vector2f size)
{
	_body.setSize(size);
}

void SfmlButton::UpdateControl()
{
	_body.setScale(GetScale());
}

void SfmlButton::Draw()
{
	if (_owner != nullptr)
	{
		_body.setPosition(GetPosition());
		_owner->draw(_body);
	}
	else
	{
		//This is place for Log
	}
}

SfmlButton::~SfmlButton()
{
}
