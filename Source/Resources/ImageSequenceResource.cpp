#include "ImageSequenceResource.h"

ImageSequenceResource::ImageSequenceResource(const std::string& id, const std::string& name, const std::vector<float>& settings):PictureResource(id, name)
{
	_widthFrame = settings[0];
	_heightFrame = settings[1];
	_countFrames = static_cast<int>(settings[2]);
	if (settings.size() == 6)
	{
		_colorForMask = new sf::Color(static_cast<int>(settings[3]), static_cast<int>(settings[4]), static_cast<int>(settings[5]),0);
	}
	else
		_colorForMask = nullptr;
}

void ImageSequenceResource::Load() 
{
	PictureResource::Load();
	_image = PictureResource::Get();
	if (_colorForMask == nullptr)
	{
		sf::Color* _colorFirstPixel = new sf::Color(_image->getPixel(0, 0));
		SetMaskFromColor(_image, *_colorFirstPixel);
	}
	else
	{
		SetMaskFromColor(_image, *_colorForMask);
	}
	CreateFrames();
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
	image->createMaskFromColor(color);
}

void ImageSequenceResource::CreateFrames()
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

			_texture.loadFromImage(*_image,sf::IntRect(widthFrame, heightFrame, _widthFrame, _heightFrame));
			
			_textures.push_back(_texture);
			++_currentCountFrames;
		}
	}

}