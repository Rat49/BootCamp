#pragma once
#include "Widget.h"
class Label :
	public Widget
{
public:
	Label(const std::string & content, const sf::Font & font, sf::Vector2f position, const std::string& name);

	void SetFillColor(const sf::Color & color);
	void SetOutlineColor(const sf::Color & color);
	void SetFont(const sf::Font & font);
	void SetCharSize(const unsigned int size);
	void SetStyle(sf::Text::Style style);
	void SetString(const std::string content);

	sf::Color GetFillColor() const;
	sf::Color GetOutlineColor() const;
	const sf::Font * GetFont() const ;
	unsigned int GetCharSize()const;
	sf::Text::Style GetStyle() const;
	const std::string & GetContent() const;

	void UpdateControl() override;
	void Draw() override;
	~Label();
private:
	sf::Text _content;
};
