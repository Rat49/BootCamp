#pragma once
#include "Widget.h"
class ScrollBar :
	public Widget
{
public:
	ScrollBar(const std::string & name, sf::Vector2f position);
	~ScrollBar();
};

