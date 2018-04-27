#include "AnimationPlayer.h"
#include <SFML\Graphics.hpp>
#include <cassert>

AnimationPlayer::AnimationPlayer()
{
	Init(nullptr, nullptr, false);
}

AnimationPlayer::AnimationPlayer(sf::Sprite* animatedSprite, ImageSequenceResource* animation, bool isLooped)
{
	Init(animatedSprite, animation, isLooped);
}

void AnimationPlayer::Init(sf::Sprite* animatedSprite, ImageSequenceResource* animation, bool isLooped)
{
	_animation = animation;
	_animatedSprite = animatedSprite;
	_spriteSheet = _animation == nullptr ? std::vector<sf::Texture>() : _animation->Get();
	_isLooped = isLooped;
	_currentFrame = 0;
	_isStopped = true;
	_framesCount = _spriteSheet.size();
	_animationTime = _animation == nullptr ? sf::Time::Zero : _animation->GetTime();
	_frameTime = _framesCount == 0 ? sf::Time::Zero : (_animationTime / static_cast<float>(_framesCount));
	_playingTime = sf::Time::Zero;
	_defaultAnimationTime = _animationTime;
}

AnimationPlayer::~AnimationPlayer()
{
	_animation->DecRefCounter();
}

void AnimationPlayer::Start()
{
	assert(_framesCount != 0);

	_animationTime = _defaultAnimationTime;
	_frameTime = _animationTime / static_cast<float>(_framesCount);
	_isStopped = false;
}

void AnimationPlayer::Start(sf::Time animationTime)
{
	assert(_framesCount != 0);

	_animationTime = animationTime;
	_frameTime = _animationTime / static_cast<float>(_framesCount);
	_isStopped = false;
}

void AnimationPlayer::Pause()
{
	_isStopped = true;
	_playingTime = sf::Time::Zero;
}

void AnimationPlayer::Stop()
{
	_currentFrame = 0;
	_playingTime = sf::Time::Zero;
	_isStopped = true;
}

void AnimationPlayer::Reset()
{
	_currentFrame = 0;
	_playingTime = sf::Time::Zero;
	_isStopped = false;
}

void AnimationPlayer::Update(sf::Time deltaTime)
{	
	if (_isStopped)
	{
		return;
	}

	_playingTime += deltaTime;
	if (_playingTime <= _frameTime)
	{
		return;
	}

	assert(_animatedSprite != nullptr);

	_playingTime = sf::Time::Zero;
	int64_t frameNumber = _currentFrame + 1;

	if (_isLooped)
	{
		_currentFrame = frameNumber == _framesCount ? 0 : frameNumber;
		_animatedSprite->setTexture(_spriteSheet[_currentFrame], true);
	}
	else
	{
		if (frameNumber < _framesCount)
		{
			_currentFrame = frameNumber;
			_animatedSprite->setTexture(_spriteSheet[_currentFrame], true);
		}
		else
		{
			Stop();
		}
	}
}

void AnimationPlayer::SetLooped(bool isLooped)
{
	_isLooped = isLooped;
}

sf::Sprite* AnimationPlayer::GetSprite() const
{
	return _animatedSprite;
}

int AnimationPlayer::GetWidth() const
{
	return _animation->GetWidth();
}

int AnimationPlayer::GetHeight() const
{
	return _animation->GetHeight();
}
