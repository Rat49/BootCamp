#pragma once
#include "Bullet.h"

class Rocket final : public Bullet
{
private:
	AnimationPlayer& _rocketAnimation;
public:
	Rocket(sf::Vector2f rocketDirection, AnimationPlayer& rocketAnimation);
	~Rocket();
	void Update(sf::Time deltaTime);
};
