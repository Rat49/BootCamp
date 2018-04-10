#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceManager.h"

class AnimationPlayer : public sf::Drawable
{
public:
	AnimationPlayer(sf::Sprite* animatedSprite, const std::vector<sf::Texture>& spriteSheet, bool isLooped);

	//AnimationResource& GetAnimation() const;
	//void SetAnimation(AnimationResource animation);
	//void SetSpriteSheet();
	void Start();
	void Start(sf::Time AnimationTime);
	void Pause();
	void Reset();
	void Update();
	void SetLooped(bool isLooped);

	~AnimationPlayer();

private:
	//AnimationResource& _animation;
	const std::vector<sf::Texture>& _spriteSheet;
	sf::Sprite* _animatedSprite;
	unsigned int _currentFrame;
	bool _isLooped;
	bool _isStoped;
	unsigned int _framesNumber;
	sf::Time _animationTime;
	sf::Time _frameTime;
	sf::Time _currentTime;
	sf::Clock _clock;
};
