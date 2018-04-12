#pragma once
#include <SFML\Graphics.hpp>
#include "PictureResource.h"
#include <string>

class ImageSequenceResource : public PictureResource
{
public:

	ImageSequenceResource(const std::string& id, const std::string& name, std::multimap<std::string, std::string>* settings);

	void Load() override;
	void Unload() override;
	std::vector<sf::Texture>& Get();
	sf::Time& GetTime();
	void SetMaskFromColor(sf::Image* image, sf::Color color);

	~ImageSequenceResource() override;

private:

	int _widthFrame;
	int _heightFrame;
	int _countFrames;
	sf::Time _timeAnimation;
	std::vector<sf::Color*> _colorForMask;
	sf::Image* _image;
	sf::Texture _texture;
	std::vector<sf::Texture> _textures;
	void CreateFrames(sf::Image* image);
	sf::Color* _colorFirstPixel;

};
