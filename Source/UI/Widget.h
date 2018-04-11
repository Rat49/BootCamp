#pragma once
#include <SFML\Graphics.hpp>

class Widget
{
public:
	Widget(const std::string & name, sf::Vector2f position);
	const std::string _name;
	
	void SetPosition(float x, float y);

	sf::Vector2f GetPosition() const;
	
	void AddOwner(sf::RenderWindow * host);

	virtual void Update() {};

	virtual void Draw() {};

	virtual ~Widget();
private:
	sf::Vector2f _position;
protected:
	sf::RenderWindow * _owner;
};

