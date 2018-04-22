#pragma once
#include "Bullet.h"
#include "DrawableManager.h"

class OrdinaryBullet final : public Bullet
{
private:
	//AnimationPlayer* _ordinaryBulletAnimation;
	//ImageSequenceResource*  _bulletAnimationImseq;
	sf::Texture* _bulletTexture;
	sf::Sprite _ordinaryBulletSprite;
	const float _speedValue;
	bool _life;
public:
	OrdinaryBullet();
	~OrdinaryBullet();
	//void Init(const sf::Vector2f position, const sf::Vector2f bulletDirection, ImageSequenceResource& bulletAnimationImseq);
	void Init(sf::Sprite& ordinaryBulletSprite, const sf::Vector2f position, const sf::Vector2f bulletDirection, sf::Texture& bulletTexture);
	sf::Sprite* GetSprite();
	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(sf::Time& deltaTime) override;
	void Reset() override;
	bool GetLifeStatus() const;
};
