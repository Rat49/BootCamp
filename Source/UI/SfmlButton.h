#pragma once
#include "Widget.h"
#include <SFML\Graphics.hpp>
class SfmlButton:
	public Widget
{
public:
	SfmlButton(const sf::Vector2f size, const sf::Vector2f pos,const std::string & name);
	bool IsClicked(sf::Vector2i cursor_pos) const;
	void SetColor(const sf::Color & color);
	void SetSize(const sf::Vector2f size);
	void UpdateControl() override;
	void Draw() override;
	~SfmlButton();
private:
	sf::RectangleShape _body;
	
};

