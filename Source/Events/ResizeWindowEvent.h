#pragma once
#include <SFML/Graphics.hpp>
#include "EventSystem.h"
#include "Event.h"

class ResizeWindowEvent : public Event
{
public:
	sf::Vector2u _windowsize;
	ResizeWindowEvent(const sf::Vector2u windowsize) :
	_windowsize(windowsize)
	{
	};
};