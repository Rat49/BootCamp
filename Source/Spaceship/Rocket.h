#pragma once
#include "Bullet.h"

class Rocket final : public Bullet
{
public:
	Rocket();

	void Init(const sf::Vector2f& position, const sf::Vector2f& rocketDirection, sf::Texture& rocketTexture);

	const sf::Sprite* GetSprite();
	void AddToDrawableManager() override;
	int GetZOrder() const override;
	void Draw(sf::RenderWindow& window) override;
	void Update(const sf::Time& deltaTime) override;
	void Reset() override;

private:
	sf::Texture* _rocketTexture;
	sf::Sprite _rocketSprite;
	const float _speedValuePixelsPerSecond;
	const sf::Time _speedDelayTime;
	sf::Vector2f _direction;
	const float _deltaSpeedValue;
	sf::Time _timeAfterShot;
	sf::Vector2f _rocketScale;
};
