#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "Widget.h"

class Label final : public Widget
{
public:
	Label(const std::string& content, const sf::Font& font, const sf::Vector2f position, const std::string& name, sf::RenderWindow& owner);
	~Label();

	void SetFillColor(const sf::Color& color);
	void SetOutlineColor(const sf::Color& color);
	void SetFont(const sf::Font& font);
	void SetCharSize(const unsigned int size);
	void SetStyle(sf::Text::Style style);
	void SetString(const std::string& content);

	sf::Color GetFillColor() const;
	sf::Color GetOutlineColor() const;
	const sf::Font* GetFont() const ;
	unsigned int GetCharSize()const;
	sf::Text::Style GetStyle() const;
	std::string GetContent() const;

	void OnResize() override;
	void Draw() override;

private:
	void operator=(const Label&) = delete;
	Label(const Label&) = delete;

	sf::Text _content;
};
