#pragma once
#include <SFML\Graphics.hpp>
class UI;
class Widget 
{
	friend UI;
public:
	
	const std::string _name;
	
	void SetPosition(float x, float y);
	void SetScale(sf::Vector2f scale);

	sf::Vector2f GetPosition() const;	
	sf::Vector2f GetScale() const;

	//void AddOwner(sf::RenderWindow & host);

	void Resize();

	virtual void Draw() {};

	virtual ~Widget();
private:
	sf::Vector2f _position;
	sf::Vector2f _scale;
protected:
	Widget(const std::string & name, sf::Vector2f position, sf::RenderWindow & owner);
	virtual void OnResize() {};
	sf::RenderWindow & _window;
};

