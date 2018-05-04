#include "SfmlButton.h"


SfmlButton::SfmlButton(const sf::Font& font, const sf::Vector2f size, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner) :
	Widget(name,position,owner),
	_text(name,font)
{	
	_body = sf::RectangleShape(size);
	_body.setPosition(position);
	_body.setOrigin(_body.getLocalBounds().width /2 , _body.getLocalBounds().height /2);
	_text.setOrigin(_text.getLocalBounds().width / 2, _text.getLocalBounds().height / 2);
	_text.setPosition(_body.getPosition());
	_text.setFillColor(sf::Color::Black);
}

SfmlButton::SfmlButton(const sf::Vector2f size, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner):
	Widget(name, position, owner),
	_text()
{
	_body = sf::RectangleShape(size);
	_body.setPosition(position);
	_body.setOrigin(_body.getLocalBounds().width / 2, _body.getLocalBounds().height / 2);
}

bool SfmlButton::IsClicked(const sf::Vector2i cursor_pos) const
{
	if (!_body.getGlobalBounds().contains(static_cast<sf::Vector2f>(cursor_pos)))
	{
		return false;
	}
	else
	{		
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

void SfmlButton::SetText(const std::string& text,const sf::Font& font = sf::Font::Font())
{
	if (&font != &sf::Font::Font())
	{
		_text.setFont(font);
	}
	_text.setString(text);
}

void SfmlButton::SetColorText(const sf::Color& color)
{
	_text.setFillColor(color);
	_text.setOutlineColor(color);
}

void SfmlButton::SetCharSize(const unsigned int size)
{
	_text.setCharacterSize(size);
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
	_text.setScale(GetScale());
}

void SfmlButton::Draw()
{	
	_body.setPosition(GetPosition());
	_text.setPosition(_body.getPosition());
	_window.draw(_body);	
	_window.draw(_text);
}

SfmlButton::~SfmlButton()
{
}
