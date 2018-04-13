#pragma once
#include "SFML\Graphics.hpp"
#include "EventSystem.h"
#include <cstdint>

class DebugConsoleKeyEvent : public Event
{
public:
	sf::Event _event;
	DebugConsoleKeyEvent(sf::Event& event);
};