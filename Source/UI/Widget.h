#pragma once
#include <SFML\Graphics.hpp>

class Widget
{
public:
	Widget(const std::string & name, sf::Vector2f position, sf::RenderWindow& caller);
	const std::string _name;
	sf::Vector2f GetPosition() const;
	void SetPosition(float x, float y);
	sf::RenderWindow& GetOwner();
	virtual void Draw() {};
	virtual ~Widget();
private:
	sf::Vector2f _position;
	sf::RenderWindow& _owner;
};

