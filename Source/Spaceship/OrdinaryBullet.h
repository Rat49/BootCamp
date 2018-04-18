#pragma once
#include "Bullet.h"

class OrdinaryBullet final : public Bullet
{
private:
	AnimationPlayer& _ordinaryBulletAnimation;
	const float _speedValue;
public:
	OrdinaryBullet(sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation);
	~OrdinaryBullet();
	virtual void Update(sf::Time deltaTime) final;
	virtual void setZOrder(int zOrder);
	virtual int getZOrder() const;
};
