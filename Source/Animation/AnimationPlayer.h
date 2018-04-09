#pragma once
#include "SFML\Graphics.hpp"

class AnimationPlayer : public sf::Drawable
{
public:
	AnimationPlayer();

	void Start();
	void Pause();
	void Stop();
	void draw();
	AnimationResource& GetAnimation();
	void SetAnimation();

	~AnimationPlayer();

private:
	AnimationResource _animation;
	bool isLooped;
	bool isStoped;
};
