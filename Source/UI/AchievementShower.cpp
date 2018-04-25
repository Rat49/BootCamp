#include "AchievementShower.h"

AchievementShower::AchievementShower(const sf::Font& font, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner) :
	Widget(name, position, owner),
	_text("", font),
	_liveInFrame(0)
{
	_picture.setPosition(GetPosition());
	_text.setPosition(GetPosition());
}


void AchievementShower::ImplementAchivement(const std::string & text, sf::Image * picture, const int timeLive)
{
	_liveInFrame = timeLive;
	_text.setString(text);
	_texture.loadFromImage(*picture);
	_picture.setTexture(_texture,true);
	_text.setPosition(GetPosition().x, GetPosition().y + _texture.getSize().y);
}

AchievementShower::~AchievementShower()
{
}

void AchievementShower::OnResize()
{
	_text.setScale(GetScale());
	_picture.setScale(GetScale());
}

void AchievementShower::Draw()
{
	if (_liveInFrame > 0)
	{
		--_liveInFrame;
		_window.draw(_text);
		_window.draw(_picture);
	}
}
