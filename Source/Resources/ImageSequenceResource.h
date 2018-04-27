#pragma once
#include <string>
#include <SFML\Graphics.hpp>
#include "PictureResource.h"

class ImageSequenceResource : public PictureResource
{
public:
	ImageSequenceResource(const std::string& id, const std::string& name, const std::multimap<const std::string, const std::string>& settings);
	~ImageSequenceResource() override;

	void Load() override;
	void Unload() override;
	std::vector<sf::Texture>& Get();
	sf::Time& GetTime();
	void SetMaskFromColor(sf::Image* image, sf::Color color);
	const int GetHeight() const;
	const int GetWidth() const;

private:
	void CreateFrames(sf::Image* image);

	int _widthFrame;
	int _heightFrame;
	int _countFrames;
	sf::Time _timeAnimation;
	std::vector<sf::Color> _colorForMask;
	sf::Image* _image;
	sf::Texture _texture;
	std::vector<sf::Texture> _textures;
	sf::Color* _colorFirstPixel;
};
