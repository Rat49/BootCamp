#pragma once
#include "Bullet.h"

class OrdinaryBullet final : public Bullet
{
private:
	AnimationPlayer& _ordinaryBulletAnimation;
public:
	OrdinaryBullet(sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation);
	~OrdinaryBullet();
	void Update(sf::Time deltaTime);
};
