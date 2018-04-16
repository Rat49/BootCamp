#pragma once
#include "Widget.h"
#include <SFML\Graphics.hpp>
class SfmlButton:
	public Widget
{
public:
	bool IsClicked(const sf::Vector2i cursor_pos) const;
	SfmlButton(const sf::Vector2f size, const sf::Vector2f pos, const std::string & name,sf::RenderWindow & owner);

	virtual void SetFillColor(const sf::Color & color);
	virtual void SetOutlineColor(const sf::Color & color);
	virtual void SetSize(const sf::Vector2f size);
	
	sf::Vector2f GetSize() const;
	sf::Color GetFillColor() const;
	sf::Color GetOutlineColor() const;

	void OnResize() override;
	void Draw() override;
	virtual ~SfmlButton();	
protected:
	
	sf::RectangleShape _body;
	
};

