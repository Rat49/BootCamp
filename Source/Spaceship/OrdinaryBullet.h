#pragma once
#include "Bullet.h"

class OrdinaryBullet final : public Bullet
{
private:
	AnimationPlayer* _ordinaryBulletAnimation;
	ImageSequenceResource&  _bulletAnimationImseq;
	sf::Sprite* _ordinaryBulletSprite;
	const float _speedValue;

public:
	//OrdinaryBullet(sf::Vector2f position, sf::Vector2f bulletDirection, AnimationPlayer* bulletAnimation);
	OrdinaryBullet(sf::Vector2f position, sf::Vector2f bulletDirection, ImageSequenceResource& bulletAnimationImseq);
	~OrdinaryBullet();
	void Init(sf::Vector2f position, sf::Vector2f bulletDirection);
	sf::Sprite* GetSprite();

	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;

	void Update(sf::Time deltaTime) final override;

	void Reset() override;
};
