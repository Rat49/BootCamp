#pragma once
#include "EventSystem.h"
#include "SFML\Graphics.hpp"
#include <cstdint>

class DebugConsoleKeyEvent : public Event
{
public:
	sf::Event _event;
	DebugConsoleKeyEvent(sf::Event& event);
};