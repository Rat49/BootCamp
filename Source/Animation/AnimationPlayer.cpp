#include "AnimationPlayer.h"
#include "ResourceManager.h"

AnimationPlayer::AnimationPlayer(sf::Sprite* animatedSprite, const std::vector<sf::Texture>& spriteSheet, sf::Time animationTime, bool isLooped) :
	_animatedSprite(animatedSprite),
	_spriteSheet(spriteSheet),
	_isLooped(isLooped),
	_currentFrame(0),
	_isStoped(true),
	_framesCount(spriteSheet.size()),
	_animationTime(animationTime),
	_frameTime(_animationTime / static_cast<float>(_framesCount)),
	_playingTime(sf::seconds(0.0f)),
	_defaultAnimationTime(animationTime)
{

}

void AnimationPlayer::Start()
{
	_isStoped = false;
}

void AnimationPlayer::Start(sf::Time animationTime)
{
	_animationTime = animationTime;
	_frameTime = _animationTime / static_cast<float> (_framesCount);
	_isStoped = false;
}

void AnimationPlayer::Pause()
{
	_isStoped = true;
	_playingTime = sf::milliseconds(0.0f);
}

void AnimationPlayer::Reset()
{
	_currentFrame = 0;
	_playingTime = sf::milliseconds(0.0f);
	_isStoped = true;
}


void AnimationPlayer::Update(sf::Time deltaTime)
{	
	if (!_isStoped)
	{
		_playingTime += deltaTime;
		if (_playingTime > _frameTime)
		{
			_playingTime = sf::milliseconds(0.0f);
			int64_t frameNumber = _currentFrame + 1;

			if (_isLooped)
			{
				if (frameNumber == _framesCount)
				{
					_currentFrame = 0;
				}
				else
				{
					_currentFrame = frameNumber;
				}
				_animatedSprite->setTexture(_spriteSheet[_currentFrame]);
			}
			else
			{
				if (frameNumber < _framesCount)
				{
					_currentFrame = frameNumber;
					_animatedSprite->setTexture(_spriteSheet[_currentFrame]);

				}
				else
				{
					Reset();
				}
			}
		}
	}
}

void AnimationPlayer::SetLooped(bool isLooped)
{
	_isLooped = isLooped;
}

void AnimationPlayer::DefaultAnimationTime()
{
	_animationTime = _defaultAnimationTime;
	_frameTime = _animationTime / static_cast<float> (_framesCount);
}

AnimationPlayer::~AnimationPlayer()
{
}