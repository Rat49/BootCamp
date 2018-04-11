#include "SfmlButton.h"

#include <iostream>

SfmlButton::SfmlButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string & name, sf::RenderWindow& caller) :
	
	Widget(name,pos,caller)
{	
	_body = sf::RectangleShape(size);
	_body.setPosition(pos);
	Draw();
}

bool SfmlButton::IsClicked(sf::Vector2i cursor_pos) const
{
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

sf::RectangleShape & SfmlButton::GetBody()
{
	return _body;
}

void SfmlButton::Draw()
{
	_body.setPosition(GetPosition());
	GetOwner().draw(_body);
}

SfmlButton::~SfmlButton()
{
}
