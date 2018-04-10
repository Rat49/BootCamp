#include "SfmlButton.h"

#include <iostream>

SfmlButton::SfmlButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string & name, sf::RenderWindow& caller) :
	RectangleShape(size),
	Widget(name,caller)
{	
	setPosition(pos);
	Draw();
}

bool SfmlButton::IsClicked(sf::Vector2i cursor_pos) const
{
	if (!getGlobalBounds().contains(static_cast<sf::Vector2f>(cursor_pos)))
	{
		return false;
	}
	else
	{
		std::cout << "clicked!! ";
		return true;
	}
}

void SfmlButton::Draw()
{
	this->GetOwner().draw(*this);
}

SfmlButton::~SfmlButton()
{
}
