#include "AchievementShower.h"

AchievementShower::AchievementShower(const sf::Font& font, const sf::Vector2f position, const std::string & name, const std::string & description, sf::RenderWindow & owner) :
	Widget(name, position, owner),
	_name("", font),
	_description("", font),
	_liveTime(sf::Time::Zero),
	_timer()
{
	Widget::SetPosition(sf::Vector2f( _window.getSize().x/3, _window.getSize().y - _window.getSize().y/3));
	_picture.setPosition(GetPosition());
	_name.setPosition(GetPosition());
	_description.setPosition(GetPosition());
	_description.setCharacterSize(24);
}


void AchievementShower::ImplementAchivement(const std::string & name, const std::string & description,sf::Image * picture, const sf::Time liveTime)
{
	_timer.restart();
	_liveTime = liveTime;
	_name.setString(name);
	_description.setString(description);
	_texture.loadFromImage(*picture);
	_picture.setTexture(_texture,true);
	_name.setPosition(GetPosition().x + 110, GetPosition().y+10);
	_description.setPosition(GetPosition().x + 110, GetPosition().y + _name.getCharacterSize() + 25);
}

AchievementShower::~AchievementShower()
{
}

void AchievementShower::OnResize()
{
	_name.setScale(GetScale());
	_description.setScale(GetScale());
	_picture.setScale(GetScale());
}

void AchievementShower::Draw()
{
	if (_timer.getElapsedTime() < _liveTime)
	{		
		_window.draw(_picture);
		_window.draw(_name);
		_window.draw(_description);
	}
}
