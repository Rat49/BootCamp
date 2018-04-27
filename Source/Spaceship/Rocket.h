#pragma once
#include "Bullet.h"
#include "ParticleAssets.h"

class Rocket final : public Bullet
{
public:
    Rocket();

    void Init(const sf::Vector2f& position, const sf::Vector2f& rocketDirection, sf::Texture& rocketTexture/*, RocketParticle& rocketParticle*/);

    const sf::Sprite* GetSprite();
    void AddToDrawableManager() override;
    int GetZOrder() const override;
    void Draw(sf::RenderWindow& window) override;
    void Update(const sf::Time& deltaTime) override;
    void Reset() override;
    bool GetLifeStatus() const;
    void OnCollisionHandler(const Event& cEvent);

private:
    sf::Texture* _rocketTexture;
    sf::Sprite _rocketSprite;
    //RocketParticle* _rocketParticle;
    sf::Vector2f _rocketScale;
    const float _speedValuePixelsPerSecond;
    const sf::Time _speedDelayTime;
    sf::Vector2f _direction;
    const float _deltaSpeedValue;
    sf::Time _timeAfterShot;
    bool _isAlive;
};
