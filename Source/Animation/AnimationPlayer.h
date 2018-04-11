#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceManager.h"

class AnimationPlayer 
{
public:
	AnimationPlayer(sf::Sprite* animatedSprite, const std::vector<sf::Texture>& spriteSheet, sf::Time animationTime, bool isLooped);

	void Start();
	void Start(sf::Time AnimationTime);
	void Pause();
	void Reset();
	void Update(sf::Time deltaTime);
	void SetLooped(bool isLooped);
	void DefaultAnimationTime();

	~AnimationPlayer();

private:
	const std::vector<sf::Texture>& _spriteSheet;
	sf::Sprite* _animatedSprite;
	int64_t _currentFrame;
	bool _isLooped;
	bool _isStoped;
	int64_t _framesCount;
	sf::Time _defaultAnimationTime;
	sf::Time _animationTime;
	sf::Time _frameTime;
	sf::Time _playingTime;
};
