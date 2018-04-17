#include "SfmlButton.h"

#include <iostream>

SfmlButton::SfmlButton(const sf::Vector2f size, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner) :	
	Widget(name,position,owner)
{	
	_body = sf::RectangleShape(size);
	_body.setPosition(position);
	_body.setOrigin(_body.getLocalBounds().width /2 , _body.getLocalBounds().height /2);
}

bool SfmlButton::IsClicked(const sf::Vector2i cursor_pos) const
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

void SfmlButton::SetFillColor(const sf::Color & color)
{
	_body.setFillColor(color);
}

void SfmlButton::SetOutlineColor(const sf::Color & color)
{
	_body.setOutlineColor(color);
}

void SfmlButton::SetSize(const sf::Vector2f size)
{
	_body.setSize(size);
}

sf::Vector2f SfmlButton::GetSize() const
{
	return _body.getSize();
}

sf::Color SfmlButton::GetFillColor() const
{
	return _body.getFillColor();
}

sf::Color SfmlButton::GetOutlineColor() const
{
	return _body.getOutlineColor();
}

void SfmlButton::OnResize()
{
	_body.setScale(GetScale());
}

void SfmlButton::Draw()
{	
	_body.setPosition(GetPosition());
	_window.draw(_body);	
}

SfmlButton::~SfmlButton()
{
}
