#pragma once
#include "Bullet.h"

class OrdinaryBullet final : public Bullet
{
private:
	AnimationPlayer& _ordinaryBulletAnimation;
	const float _speedValue;
public:
	OrdinaryBullet(sf::Vector2f bulletPosition, sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation);
	~OrdinaryBullet();
	
	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(sf::Time deltaTime) override;
};
