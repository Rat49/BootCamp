#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceManager.h"

class AnimationPlayer final
{
public:
	AnimationPlayer(sf::Sprite* animatedSprite, ImageSequenceResource* animation, bool isLooped);

	void Start();
	void Start(sf::Time AnimationTime);
	void Pause();
	void Reset();
	void Update(sf::Time deltaTime);
	void SetLooped(bool isLooped);

	~AnimationPlayer();

private:
	sf::Sprite* _animatedSprite;
	ImageSequenceResource* _animation;
	const std::vector<sf::Texture>& _spriteSheet;
	int64_t _currentFrame;
	bool _isLooped;
	bool _isStopped;
	int64_t _framesCount;
	sf::Time _animationTime;
	sf::Time _defaultAnimationTime;
	sf::Time _frameTime;
	sf::Time _playingTime;
};
