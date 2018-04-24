#pragma once
#include "Bullet.h"

class OrdinaryBullet final : public Bullet
{
private:
	sf::Texture* _bulletTexture;
	sf::Sprite _ordinaryBulletSprite;
	const float _speedValue;
public:
	OrdinaryBullet();
	~OrdinaryBullet();
	void Init(const sf::Vector2f position, const sf::Vector2f bulletDirection, sf::Texture& bulletTexture);
	sf::Sprite* GetSprite();
	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(sf::Time& deltaTime) override;
	void Reset() override;
};
