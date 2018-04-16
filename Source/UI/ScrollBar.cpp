#include "ScrollBar.h"
#include <iostream>



ScrollBar::ScrollBar(const float length, const sf::Vector2f pos, const std::string & name, sf::RenderWindow & owner):
	SfmlButton(sf::Vector2f(10,20), sf::Vector2f((pos.x + length/2),(pos.y - 10)),name,owner),
	_isGrabbed(false),
	_rail(sf::Vector2f(length,5))
{
	_rail.setPosition(GetPosition());
}

void ScrollBar::ChangeStateGrab(sf::Vector2i position)
{
	_isGrabbed =  IsClicked(position);
	std::cout << " _isGrabbed = " << _isGrabbed << " " ;
}
void ScrollBar::UnGrab()
{
	_isGrabbed = false;
}
void ScrollBar::SetSliderPosition(const float position)
{
	_sliderValue = position;
	if (0 <= position && position <= 1)
	{
		SetPosition(sf::Vector2f(_rail.getPosition().x + _sliderValue * _rail.getSize().x * _rail.getScale().x,_rail.getPosition().y));
		_body.setPosition(GetPosition());
	}	
}
float ScrollBar::GetSliderPosition() const
{
	return _sliderValue;
}
void ScrollBar::SetFillColor(const sf::Color & color)
{
	_rail.setFillColor(color);
	_body.setFillColor(color);
}
void ScrollBar::SetLength(const float size)
{
	_rail.setSize(sf::Vector2f(size,5));
}
float ScrollBar::GetLength() const
{
	return _rail.getSize().x;
}
void ScrollBar::UpdatePosition() 
{	
	auto cursorPosition = sf::Mouse::getPosition(_window);
	if (_isGrabbed)
	{
		SetSliderPosition((cursorPosition.x - _rail.getPosition().x) / (_rail.getSize().x * _rail.getScale().x));
	}			
}

void ScrollBar::OnResize() 
{
	_body.scale(GetScale());
	_rail.scale(GetScale());
}

void ScrollBar::Draw()
{		
	UpdatePosition();
	_window.draw(_body);
	_window.draw(_rail);
}


ScrollBar::~ScrollBar()
{
}

