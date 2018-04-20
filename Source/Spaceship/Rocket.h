#pragma once
#include "Bullet.h"

class Rocket final : public Bullet
{
private:
	AnimationPlayer& _rocketAnimation;
	const float _speedValue;
	sf::Time _speedDelayTime;
public:
	Rocket(sf::Vector2f position, sf::Vector2f rocketDirection, AnimationPlayer& rocketAnimation);
	~Rocket();

	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(sf::Time deltaTime) override;
};
