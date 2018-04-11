#include "Label.h"



Label::Label(const std::string & content, const std::string & name,sf::Vector2f position):
	Widget(name,position)
{
	_content.setString(content);
	_content.setPosition(position);
	_content.setFont(sf::Font::Font());
//	_content.setColor(sf::Color::White);
	Draw();
}



void Label::Draw()
{
	_owner->draw(_content);
}


Label::~Label()
{
}
