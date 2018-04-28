#pragma once
#include "Widget.h"
class UI;
class Picture :
	public Widget
{
public:
	friend UI;

	void OnResize() override;
	void Draw() override;

	~Picture();
private:
	void operator=(const Picture&) = delete;
	Picture(const Picture&) = delete;
	Picture( const sf::Image & img, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner);
	sf::Texture _texture;
	sf::Sprite _sprite;
	
};

