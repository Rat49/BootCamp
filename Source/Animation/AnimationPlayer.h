#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceManager.h"

class AnimationPlayer : public sf::Drawable
{
public:
	AnimationPlayer(AnimationResource& animation, bool isLooped);

	AnimationResource& GetAnimation() const;
	void SetAnimation(AnimationResource animation);
	void Start();
	void Start(sf::Time AnimationTime);
	void Pause();
	void Reset();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states);
	void SetLooped(bool isLooped);

	~AnimationPlayer();

private:
	AnimationResource& _animation;
	sf::Sprite _unimationSprite;
	unsigned int _activeFrameId;
	bool _isLooped;
	bool _isStoped;
	sf::Time _animationTime;
	sf::Time _frameTime;
};
