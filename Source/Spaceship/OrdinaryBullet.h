#pragma once
#include "Bullet.h"

class OrdinaryBullet final : public Bullet
{
private:
	AnimationPlayer& _ordinaryBulletAnimation;
public:
	OrdinaryBullet(sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation);
	~OrdinaryBullet();
	virtual void Update(sf::Time deltaTime) final;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
