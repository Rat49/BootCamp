#include "AnimationPlayer.h"
#include "ResourceManager.h"

AnimationPlayer::AnimationPlayer(sf::Sprite* animatedSprite, const std::vector<sf::Texture>& spriteSheet, bool isLooped) : 
	_animatedSprite(animatedSprite),
	_spriteSheet(spriteSheet),
	_isLooped(isLooped),
	_currentFrame(0),
	_isStoped(true),
	_framesNumber(std::abs(std::distance(_spriteSheet.end(), _spriteSheet.begin()))),
	_animationTime(sf::seconds(0.2f)),
	_frameTime(sf::seconds(_animationTime.asSeconds() / static_cast<float>(_framesNumber)))
{
	_clock.getElapsedTime();
}


//void AnimationPlayer::SetSpriteSheet(std::vector<sf::Texture> spriteSheet)
//{
//	_spriteSheet = spriteSheet;
//}

void AnimationPlayer::Start()
{
	_isStoped = false;
	_clock.restart();
}

void AnimationPlayer::Start(sf::Time animationTime)
{
	_animationTime = animationTime;
	_isStoped = false;
	_clock.restart();
}

void AnimationPlayer::Pause()
{
	_isStoped = true;
	_clock.restart();
}

void AnimationPlayer::Reset()
{
	_currentFrame = 1;
	_isStoped = true;
}

void AnimationPlayer::Update()
{
	if (!_isStoped)
	{
		int64_t frameNumber = static_cast<int64_t>(_currentFrame + std::ceil(_clock.getElapsedTime().asSeconds() / _frameTime.asSeconds()));
		if (_isLooped)
		{
			_currentFrame = frameNumber % _framesNumber;
			_animatedSprite->setTexture(_spriteSheet[_currentFrame]);
		}
		else
		{
			if (frameNumber < _framesNumber)
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

void AnimationPlayer::SetLooped(bool isLooped)
{
	_isLooped = isLooped;
}

AnimationPlayer::~AnimationPlayer()
{
}