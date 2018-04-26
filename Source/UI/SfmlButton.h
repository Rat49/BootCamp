#pragma once
#include "Widget.h"
#include <SFML\Graphics.hpp>

class SfmlButton : public Widget
{
public:
	SfmlButton(const sf::Vector2f size, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner);
	virtual ~SfmlButton();

	virtual void SetFillColor(const sf::Color & color);
	virtual void SetOutlineColor(const sf::Color & color);
	virtual void SetSize(const sf::Vector2f size);
	
	sf::Vector2f GetSize() const;
	sf::Color GetFillColor() const;
	sf::Color GetOutlineColor() const;
	bool IsClicked(const sf::Vector2i cursor_pos) const;

	void OnResize() override;
	void Draw() override;

protected:
	void operator=(const SfmlButton&) = delete;
	SfmlButton(const SfmlButton&) = delete;
	
	sf::RectangleShape _body;
};

