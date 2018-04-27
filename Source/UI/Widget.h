#pragma once
#include <SFML\Graphics.hpp>

class UI;
class Widget 
{
public:
	
	const std::string _name;
	
	void SetPosition(const sf::Vector2f position);
	void SetScale(const sf::Vector2f scale);

	sf::Vector2f GetPosition() const;	
	sf::Vector2f GetScale() const;

	void Resize();

	virtual void Draw() {};

	virtual ~Widget();
private:
	sf::Vector2f _position;
	sf::Vector2f _scale;
protected:
	void operator=(const Widget&) = delete;
	Widget(const Widget&) = delete;
	Widget(const std::string & name, const sf::Vector2f position, sf::RenderWindow & owner);
	virtual void OnResize() {};
	sf::RenderWindow & _window;
};

