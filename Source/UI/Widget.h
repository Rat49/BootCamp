#pragma once
#include <string>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

class Widget
{
public:
	Widget(const std::string & name, const sf::Vector2f position, sf::RenderWindow & owner);
	virtual ~Widget();

	void SetPosition(const sf::Vector2f position);
	void SetScale(const sf::Vector2f scale);

	sf::Vector2f GetPosition() const;
	sf::Vector2f GetScale() const;

	void Resize();
	virtual void Draw() {}

protected:
	void operator=(const Widget&) = delete;
	Widget(const Widget&) = delete;

	virtual void OnResize() {}

	sf::RenderWindow & _window;

private:
	sf::Vector2f _position;
	sf::Vector2f _scale;
	const std::string _name;
};

