#include "PictureResource.h"
#include "ImageSequenceResource.h"

ImageSequenceResource::ImageSequenceResource(const std::string& id, const std::string& name, std::multimap<std::string, std::string>* settings):PictureResource(id, name)
{
	_widthFrame = std::stoi((settings->find("Width"))->second);
	_heightFrame = std::stoi((settings->find("Height"))->second);
	_countFrames = std::stoi((settings->find("FrameCount"))->second);
	_timeAnimation = sf::milliseconds(std::stoi((settings->find("AnimationTime"))->second));

	auto range = settings->equal_range("Color");
	
	for (auto currentColor = range.first; currentColor != range.second; ++currentColor)
	{
	
		std::string stringColor(currentColor->second);
		std::string delimiter = " ";

		size_t pos = 0;

		int r = 0;
		int g = 0;
		int b = 0;

		pos = stringColor.find(delimiter);

		for (int counter = 0; counter < 3; ++counter) {
		
			switch (counter)
			{
			case 0:
				r = std::stoi(stringColor.substr(0, pos));
				break;
			case 1:
				g = std::stoi(stringColor.substr(0, pos));
				break;
			case 2:
				b = std::stoi(stringColor.substr(0, pos));
				break;
			}
			stringColor.erase(0, pos + delimiter.length());
			pos = stringColor.find(delimiter);
		}
		_colorForMask.push_back(new sf::Color(r, g, b, 255));
	
	}
}

void ImageSequenceResource::Load() 
{
	PictureResource::Load();
	_image = PictureResource::Get();
	if (_colorForMask.empty())
	{
		_colorFirstPixel = new sf::Color(_image->getPixel(0, 0));
		SetMaskFromColor(_image, *_colorFirstPixel);
	}
	else
	{
		for (auto *color : _colorForMask) {
			SetMaskFromColor(_image, *color);
		}
	}
}

void ImageSequenceResource::Unload()
{
	PictureResource::Unload();
	delete _colorFirstPixel;
}

std::vector<sf::Texture>& ImageSequenceResource::Get()
{
	return _textures;
}

sf::Time& ImageSequenceResource::GetTime()
{
	return _timeAnimation;
}

ImageSequenceResource::~ImageSequenceResource()
{

}

void ImageSequenceResource::SetMaskFromColor(sf::Image* image, sf::Color color)
{
	image->createMaskFromColor(color,0);
	CreateFrames(image);
}

void ImageSequenceResource::CreateFrames(sf::Image* image)
{
	int _currentCountFrames = 0;
	for (int heightFrame = 0; heightFrame < static_cast<int>(_image->getSize().y); heightFrame += _heightFrame)
	{
		if (_currentCountFrames >= _countFrames)
			break;

		int _currentHeightFrame = heightFrame + _heightFrame;
		if (_currentHeightFrame > static_cast<int>(_image->getSize().y))
			break;

		for (int widthFrame = 0; widthFrame < static_cast<int>(_image->getSize().x); widthFrame += _widthFrame)
		{
			if (_currentCountFrames >= _countFrames)
				break;

			int _currentWidthFrame = widthFrame + _widthFrame;
			if (_currentWidthFrame > static_cast<int>(_image->getSize().x))
				break;

			_texture.loadFromImage(*image,sf::IntRect(widthFrame, heightFrame, _widthFrame, _heightFrame));
			
			_textures.push_back(_texture);
			++_currentCountFrames;
		}
	}

}