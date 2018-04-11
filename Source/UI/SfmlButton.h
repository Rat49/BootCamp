#pragma once
#include "Widget.h"
#include <SFML\Graphics.hpp>
class SfmlButton:
	public Widget
{
public:
	SfmlButton(const sf::Vector2f size, const sf::Vector2f pos,const std::string & name, sf::RenderWindow& caller);
	bool IsClicked(sf::Vector2i cursor_pos) const;
	sf::RectangleShape& GetBody();
	void Draw() override;
	~SfmlButton();
private:
	sf::RectangleShape _body;
	
};

