#pragma once
#include <SFML\Graphics.hpp>
#include "PictureResource.h"

class ImageSequenceResource : public PictureResource
{
public:
	ImageSequenceResource(const std::string& id, const std::string& name, const std::vector<float>& settings);
	void Load() override;
	void Unload() override;
	std::vector<sf::Texture>& Get();
	void SetMaskFromColor(sf::Image* image, sf::Color color);
	~ImageSequenceResource() override;
private:
	float _widthFrame;
	float _heightFrame;
	int _countFrames;
	sf::Color* _colorForMask;
	sf::Image* _image;
	sf::Texture _texture;
	std::vector<sf::Texture> _textures;
	void CreateFrames();
};
