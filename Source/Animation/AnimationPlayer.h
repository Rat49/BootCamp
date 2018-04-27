#pragma once
#include <ResourceManager.h>

namespace sf
{
	class Sprite;
	class Texture;
}

class AnimationPlayer final
{
public:
	AnimationPlayer();
	AnimationPlayer(sf::Sprite* animatedSprite, ImageSequenceResource* animation, bool isLooped);
	~AnimationPlayer();

	void Init(sf::Sprite* animatedSprite, ImageSequenceResource* animation, bool isLooped);

	void Start();
	void Start(sf::Time AnimationTime);
	void Pause();
	void Stop();
	void Reset();

	void Update(sf::Time deltaTime);

	void SetLooped(bool isLooped);
	sf::Sprite* GetSprite() const;
	int GetWidth() const;
	int GetHeight() const;

	

private:
	sf::Sprite* _animatedSprite;
	ImageSequenceResource* _animation;
	std::vector<sf::Texture> _spriteSheet;
	int64_t _currentFrame;
	bool _isLooped;
	bool _isStopped;
	int64_t _framesCount;
	sf::Time _animationTime;
	sf::Time _defaultAnimationTime;
	sf::Time _frameTime;
	sf::Time _playingTime;
};
