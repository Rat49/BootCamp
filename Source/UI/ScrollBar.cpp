#include "ScrollBar.h"
#include <iostream>



ScrollBar::ScrollBar(const float length, const sf::Vector2f pos, const std::string & name):
	SfmlButton(sf::Vector2f(10,20), sf::Vector2f((pos.x + length/2),(pos.y - 10)),name),
	_isGrab(false),
	_rail(sf::Vector2f(length,5))
{
	_rail.setPosition(GetPosition());
	Draw();
}

void ScrollBar::ChangeStateGrab(sf::Vector2i position)
{
	_isGrab =  IsClicked(position);
	std::cout << " _isGrab = " << _isGrab << " " ;
}
void ScrollBar::UnGrab()
{
	_isGrab = false;
}
void ScrollBar::SetSliderPosition(const float position)
{
	_sliderValue = position;
	if (0 <= position && position <= 1)
	{
		SetPosition(_rail.getPosition().x + _sliderValue * _rail.getSize().x * _rail.getScale().x,_rail.getPosition().y);
		_body.setPosition(GetPosition());
	}	
}
float ScrollBar::GetSliderPosition()
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
float ScrollBar::GetLength()
{
	return _rail.getSize().x;
}
void ScrollBar::UpdatePosition() 
{
	if (_owner != nullptr)
	{
		auto cursorPosition = sf::Mouse::getPosition(*_owner);

		if (_isGrab)
		{
			SetSliderPosition((cursorPosition.x - _rail.getPosition().x) / (_rail.getSize().x * _rail.getScale().x));
		}		
	}
	else
	{

	}
}

void ScrollBar::UpdateControl() 
{
	_body.scale(GetScale());
	_rail.scale(GetScale());
}

void ScrollBar::Draw()
{
	
	if (_owner != nullptr)
	{		
		UpdatePosition();
		_owner->draw(_body);
		_owner->draw(_rail);
	}
	else
	{

	}
}


ScrollBar::~ScrollBar()
{
}

