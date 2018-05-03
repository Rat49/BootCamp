#pragma once
#include "Widget.h"
#include <SFML\Graphics.hpp>
class SfmlButton:
	public Widget
{
	friend UI;
public:
	bool IsClicked(const sf::Vector2i cursor_pos) const;	

	virtual void SetFillColor(const sf::Color & color);
	virtual void SetOutlineColor(const sf::Color & color);
	virtual void SetSize(const sf::Vector2f size);

	void SetText(const std::string& text);
	void SetColorText(const sf::Color& color);
	void SetCharSize(const unsigned int size);
	
	sf::Vector2f GetSize() const;
	sf::Color GetFillColor() const;
	sf::Color GetOutlineColor() const;

	void OnResize() override;
	void Draw() override;
	virtual ~SfmlButton();	
private:
	sf::Text _text;
protected:
	void operator=(const SfmlButton&) = delete;
	SfmlButton(const SfmlButton&) = delete;
	SfmlButton(const sf::Font& font, const sf::Vector2f size, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner);
	SfmlButton(const sf::Vector2f size, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner);
	
	sf::RectangleShape _body;
	
};

