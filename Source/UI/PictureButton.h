#pragma once
#include "SfmlButton.h"
class UI;
class PictureButton :
	public SfmlButton
{
public:
	friend UI;

	void OnResize() override;
	void Draw() override;
	~PictureButton();
private:
	sf::Sprite _picture;
	sf::Texture _texture;
	void operator=(const PictureButton&) = delete;
	PictureButton(const PictureButton&) = delete;
	PictureButton(const sf::Texture& picture, const sf::Vector2f position, const std::string & name, sf::RenderWindow & owner);
	
};

