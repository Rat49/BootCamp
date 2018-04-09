#pragma once
#include <SFML\Graphics.hpp>
class myButton
{
public:
	myButton(const float w,const float h, const float x, const float y, const sf::Window& caller);
	bool isClicked();
	sf::RectangleShape _body;
	~myButton();
private:
	const sf::Window& _owner;
};

