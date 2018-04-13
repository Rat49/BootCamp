#pragma once
#include "Widget.h"
#include <SFML\Graphics.hpp>
class SfmlButton:
	public Widget
{
public:
	SfmlButton(const sf::Vector2f size, const sf::Vector2f pos,const std::string & name);
	bool IsClicked(sf::Vector2i cursor_pos) const;
	void SetFillColor(const sf::Color & color);
	void SetOutlineColor(const sf::Color & color);
	void SetSize(const sf::Vector2f size);
	
	sf::Vector2f GetSize() const;
	sf::Color GetFillColor() const;
	sf::Color GetOutlineColor() const;

	void UpdateControl() override;
	void Draw() override;
	~SfmlButton();
protected:
	sf::RectangleShape _body;
	
};

