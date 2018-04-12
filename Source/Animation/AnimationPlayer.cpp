#include "AnimationPlayer.h"
#include "ResourceManager.h"

AnimationPlayer::AnimationPlayer(sf::Sprite* animatedSprite, ImageSequenceResource* animation, bool isLooped)
	: _animation(animation)
	, _animatedSprite(animatedSprite)
	, _spriteSheet(_animation->Get())
	, _isLooped(isLooped)
	, _currentFrame(0)
	, _isStopped(true)
	, _framesCount(_spriteSheet.size())
	, _animationTime(_animation->GetTime())
	, _frameTime(_animationTime / static_cast<float>(_framesCount))
	, _playingTime(sf::seconds(0.0f))
	, _defaultAnimationTime(_animationTime)
{

}

void AnimationPlayer::Start()
{
	_animationTime = _defaultAnimationTime;
	_frameTime = _animationTime / static_cast<float> (_framesCount);
	_isStopped = false;
}

void AnimationPlayer::Start(sf::Time animationTime)
{
	_animationTime = animationTime;
	_frameTime = _animationTime / static_cast<float> (_framesCount);
	_isStopped = false;
}

void AnimationPlayer::Pause()
{
	_isStopped = true;
	_playingTime = sf::milliseconds(0.0f);
}

void AnimationPlayer::Reset()
{
	_currentFrame = 0;
	_playingTime = sf::milliseconds(0.0f);
	_isStopped = true;
}


void AnimationPlayer::Update(sf::Time deltaTime)
{	
	if (_isStopped)
	{
		return;
	}

	_playingTime += deltaTime;
	if (_playingTime > _frameTime)
	{
		_playingTime = sf::milliseconds(0.0f);
		int64_t frameNumber = _currentFrame + 1;

		if (_isLooped)
		{
			_currentFrame = frameNumber == _framesCount ? 0 : frameNumber;
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

void AnimationPlayer::SetLooped(bool isLooped)
{
	_isLooped = isLooped;
}

AnimationPlayer::~AnimationPlayer()
{
	_animation->DecRefCounter();
}