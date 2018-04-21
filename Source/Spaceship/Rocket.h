#pragma once
#include "Bullet.h"
#include "DrawableManager.h"

class Rocket final : public Bullet
{
private:
	//AnimationPlayer* _rocketAnimation;
	//ImageSequenceResource*  _rocketAnimationImseq;
	sf::Texture* _rocketTexture;
	sf::Sprite _rocketSprite;
	const float _speedValue;
	sf::Time _speedDelayTime;
public:
	Rocket();
	~Rocket();
	//void Init(const sf::Vector2f position, const sf::Vector2f rocketDirection, ImageSequenceResource& bulletAnimationImseq);
	void Init(sf::Sprite& rocketSprite, const sf::Vector2f position, const sf::Vector2f rocketDirection, sf::Texture& rocketTexture);
	sf::Sprite* GetSprite();
	void Add() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(sf::Time& deltaTime) override;
	void Reset() override;
};
