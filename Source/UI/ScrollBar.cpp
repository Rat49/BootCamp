#include "ScrollBar.h"
#include <iostream>



ScrollBar::ScrollBar(const float length, const sf::Vector2f pos, const std::string & name):
	SfmlButton(sf::Vector2f(5,20), sf::Vector2f((pos.x + length/2),(pos.y - 10)),name),
	_isGrab(false)
{
	
	Draw();
}

void ScrollBar::ChangeStateGrab(sf::Vector2i position)
{
	bool state = IsClicked(position);
	std::cout << "";
	switch (state)
	{
		case true:
			_isGrab = true;
			break;
		case false:
			_isGrab = false;
			break;
		default:
			break;
	}

	std::cout << " _isGrab = " << _isGrab << " " ;
}

void ScrollBar::UpdatePosition()
{
	if (_isGrab)
	{
		SetPosition(sf::Mouse::getPosition(*_owner).x,GetPosition().y);
	}
}

void ScrollBar::Draw()
{
	if (_owner != nullptr)
	{
		if (_isGrab)
		{
			SetPosition(sf::Mouse::getPosition(*_owner).x, sf::Mouse::getPosition(*_owner).y);
		}
		_owner->draw(_body);
	}
	else
	{

	}
}


ScrollBar::~ScrollBar()
{
}

