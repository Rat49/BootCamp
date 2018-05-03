#include "PictureButton.h"

PictureButton::PictureButton(const sf::Texture& picture, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner):
	SfmlButton(sf::Vector2f(0,0),position,name,owner),
	_texture(picture)
{
	_body.setSize(static_cast<sf::Vector2f>(picture.getSize()));
	_picture.setTexture(_texture);
}


void PictureButton::OnResize()
{
	_picture.setScale(Widget::GetScale());
}

void PictureButton::Draw()
{
	_picture.setPosition(GetPosition());
	_window.draw(_picture);
}

PictureButton::~PictureButton()
{
}
