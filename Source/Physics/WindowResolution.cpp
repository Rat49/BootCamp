#include "WindowResolution.h"

int WindowResolution::_H = 0;
int WindowResolution::_W = 0;

void WindowResolution::SetResolution(sf::RenderWindow & window)
{
	_W = window.getSize().x;
	_H = window.getSize().y;
}
