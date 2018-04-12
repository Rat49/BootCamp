#include "PictureResource.h"
#include "ImageSequenceResource.h"

ImageSequenceResource::ImageSequenceResource(const std::string& id, const std::string& name, std::map<std::string, std::string>* settings):PictureResource(id, name)
{
	_widthFrame = static_cast<int>(settings->find["Width"]->second);
	_heightFrame = static_cast<int>(settings->find["Height"]->second);
	_countFrames = static_cast<size_t>(settings->find["FrameCount"]->second);
	_timeAnimation = sf::milliseconds(settings->find["AnimationTime"]->second);

	size_t _validSettingsForColors = (settings - (static_cast<int>(ImageSequenceResource::Settings::EnumSize))) % 3;

	if (_validSettingsForColors == 0)
	{
		size_t _countColors = ((settings.size() - (static_cast<int>(ImageSequenceResource::Settings::EnumSize))) / 3);
		for (size_t currentColor = 0; currentColor < _countColors; currentColor += 1)
		{
			int colorStart = currentColor * 3 + (static_cast<int>(ImageSequenceResource::Settings::EnumSize));
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