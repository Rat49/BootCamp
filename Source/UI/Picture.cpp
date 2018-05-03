#include "Picture.h"



Picture::Picture(const sf::Texture & img, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner):
	Widget(name, position, owner),
	_isVisible(true),
	_texture(img)
{
	_sprite.setTexture(_texture);
}


void Picture::OnResize()
{
	_sprite.setScale(GetScale());
}

void Picture::Draw()
{
	if (_isVisible) {
		_sprite.setPosition(GetPosition());
		_window.draw(_sprite);
	}
}

Picture::~Picture()
{
}
