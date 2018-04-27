#pragma once
#include "Bullet.h"

class OrdinaryBullet final : public Bullet
{
private:
	sf::Texture* _bulletTexture;
	sf::Sprite _ordinaryBulletSprite;
	const float _speedValuePixelsPerSecond;
	sf::Vector2f _bulletScale;
	float _halfSpriteLength;
public:
	OrdinaryBullet();
	void Init(const sf::Vector2f& position, const sf::Vector2f& bulletDirection, sf::Texture& bulletTexture);
	const sf::Sprite* GetSprite();
	const float GetHalfSpriteLength();
	void AddToDrawableManager() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(const sf::Time& deltaTime) override;
	void Reset() override;
};
