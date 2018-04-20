#pragma once
#include "Bullet.h"

class Rocket final : public Bullet
{
private:
	AnimationPlayer* _rocketAnimation;
	ImageSequenceResource*  _rocketAnimationImseq;
	sf::Sprite _rocketSprite;
	const float _speedValue;
	sf::Time _speedDelayTime;
public:
	Rocket();
	~Rocket();
	void Init(const sf::Vector2f position, const sf::Vector2f rocketDirection, ImageSequenceResource& bulletAnimationImseq);
	sf::Sprite* GetSprite();
	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(sf::Time deltaTime) override;
	void Reset() override;
};
