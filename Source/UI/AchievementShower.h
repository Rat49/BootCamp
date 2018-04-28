#pragma once
#include "Widget.h"
#include "Label.h"
class AchievementShower :
	public Widget
{
	friend UI;
public:	
	~AchievementShower();	
private:
	void ImplementAchivement(const std::string & name, const std::string & description, sf::Image * picture, const int timeLive);
	void OnResize() override;
	void Draw() override;
	sf::Text _name;
	sf::Text _description;
	sf::Sprite _picture;
	sf::Texture _texture;
	int _liveInFrame;
	AchievementShower(const sf::Font & font, const sf::Vector2f position,
		const std::string & name, const std::string & description, sf::RenderWindow & owner);
};

