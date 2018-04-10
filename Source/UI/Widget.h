#pragma once
#include <SFML\Graphics.hpp>
class Widget
{
public:
	Widget(const std::string & name, sf::RenderWindow& caller);
	const std::string _name;
	sf::RenderWindow& GetOwner();
	virtual ~Widget();
private:
	sf::RenderWindow& _owner;
};

