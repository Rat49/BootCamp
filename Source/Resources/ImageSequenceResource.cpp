#include "ImageSequenceResource.h"

ImageSequenceResource::ImageSequenceResource(const std::string& id, const std::string& name, const std::vector<float>& settings):PictureResource(id, name)
{
	_widthFrame = settings[0];
	_heightFrame = settings[1];
	_countFrames = static_cast<size_t>(settings[2]);
	_timeAnimation = sf::seconds(settings[3]);
	size_t _validSettingsForColors = (settings.size() - 4) % 3;

	if (_validSettingsForColors == 0)
	{
		size_t _countColors = ((settings.size() - 4) / 3);
		for (size_t currentColor = 0; currentColor < _countColors; currentColor += 1)
		{
			int colorStart = currentColor * 3 + 4;
			_colorForMask.push_back(new sf::Color(static_cast<size_t>(settings[colorStart]), static_cast<size_t>(settings[colorStart +1]), static_cast<size_t>(settings[colorStart +2]),255));
		}
	}
}

void ImageSequenceResource::Load() 
{
	PictureResource::Load();
	_image = PictureResource::Get();
	if (_colorForMask.empty())
	{
		sf::Color* _colorFirstPixel = new sf::Color(_image->getPixel(0, 0));
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
}

std::vector<sf::Texture>& ImageSequenceResource::Get()
{
	return _textures;
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
	for (float heightFrame = 0; heightFrame < _image->getSize().y; heightFrame += _heightFrame)
	{
		if (_currentCountFrames >= _countFrames)
			break;

		float _currentHeightFrame = heightFrame + _heightFrame;
		if (_currentHeightFrame > _image->getSize().y)
			break;

		for (float widthFrame = 0; widthFrame < _image->getSize().x; widthFrame += _widthFrame)
		{
			if (_currentCountFrames >= _countFrames)
				break;

			float _currentWidthFrame = widthFrame + _widthFrame;
			if (_currentWidthFrame > _image->getSize().x)
				break;

			_texture.loadFromImage(*image,sf::IntRect(widthFrame, heightFrame, _widthFrame, _heightFrame));
			
			_textures.push_back(_texture);
			++_currentCountFrames;
		}
	}

}