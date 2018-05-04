#include "PictureButton.h"

PictureButton::PictureButton(const sf::Texture& picture, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner):
	SfmlButton(sf::Vector2f(0,0),position,name,owner),
	_texture(picture),
	_isVisible(true)
{
	_body.setSize(static_cast<sf::Vector2f>(picture.getSize()));
	_picture.setOrigin(_body.getLocalBounds().width / 2, _body.getLocalBounds().height / 2);
	_body.setOrigin(_body.getLocalBounds().width / 2, _body.getLocalBounds().height / 2);
	_picture.setTexture(_texture);
}


void PictureButton::OnResize()
{
	_picture.setScale(Widget::GetScale());
}

void PictureButton::Draw()
{
	if (_isVisible) {
		_picture.setPosition(GetPosition());
		_window.draw(_picture);
	}
}

PictureButton::~PictureButton()
{
}
