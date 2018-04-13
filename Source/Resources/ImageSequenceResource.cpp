#include "PictureResource.h"
#include "ImageSequenceResource.h"
#include <cassert>

enum class enumParams
{
	Width, 
	Height, 
	FrameCount, 
	AnimationTime
};

std::vector<std::string> settingsParams = { "Width", "Height", "FrameCount", "AnimationTime" };

ImageSequenceResource::ImageSequenceResource(const std::string& id, const std::string& name, const std::multimap<std::string, std::string>& settings):PictureResource(id, name)
{
	for (int param = 0; param < settingsParams.size(); ++param)
	{
		auto currentParam = settings.find(settingsParams[param]);
		if (currentParam != settings.cend())
		{
			switch (param)
			{
			case static_cast<int>(enumParams::Width):
				_widthFrame = std::stoi(currentParam->second);
				break;
			case static_cast<int>(enumParams::Height):
				_heightFrame = std::stoi(currentParam->second);
				break;
			case static_cast<int>(enumParams::FrameCount):
				_countFrames = std::stoi(currentParam->second);
				break;
			case static_cast<int>(enumParams::AnimationTime):
				_timeAnimation = sf::milliseconds(std::stoi(currentParam->second));
				break;
			}
		}
		else
		{
			switch (param)
			{
			case static_cast<int>(enumParams::Width) :
				assert(false && "Failed: the Width of frame doesn't find in settings from Config!");
			case static_cast<int>(enumParams::Height) :
				assert(false && "Failed: the Height of frame doesn't find in settings from Config!");
			case static_cast<int>(enumParams::FrameCount) :
				assert(false && "Failed: the FrameCount doesn't find in settings from Config!");
			case static_cast<int>(enumParams::AnimationTime) :
				assert(false && "Failed: the AnimationTime doesn't find in settings from Config!");
			}
		}
			
	}

	auto colors = settings.equal_range("Color");

	if (colors.first != settings.cend())
	{

		for (auto currentColor = colors.first; currentColor != colors.second; ++currentColor)
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
			_colorForMask.push_back(sf::Color(r, g, b, 255));
		}
	}
}

void ImageSequenceResource::Load() 
{
	PictureResource::Load();
	_image = PictureResource::Get();
	if (_colorForMask.empty())
	{
		sf::Color _colorFirstPixel(_image->getPixel(0, 0));
		SetMaskFromColor(_image, _colorFirstPixel);
	}
	else
	{
		for (auto &color : _colorForMask) {
			SetMaskFromColor(_image, color);
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
	_textures.clear();
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