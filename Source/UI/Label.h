#pragma once
#include "Widget.h"
class Label :
	public Widget
{
public:
	Label(const std::string & content,const std::string& name, sf::Vector2f position);
	
	void Draw() override;
	~Label();
private:
	sf::Text _content;
};

