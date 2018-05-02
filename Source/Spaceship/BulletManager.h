#pragma once
#include "EventSystem.h"
#include "BulletManagerEvents.h"
#include "Pool.h"
#include "ResourceManager.h"
#include "OrdinaryBullet.h"
#include "Rocket.h"
#include "ParticleAssets.h"
#include "Mathematics.h"
#include "SFML\Graphics.hpp"

class BulletManager final 
{
private:
	const int _totalBulletCount;
	const int _totalRocketCount;
	Pool<OrdinaryBullet> _ordinaryBulletStorage;
	Pool<Rocket> _rocketStorage;
	Pool<RocketParticle> _particleStorage;
	
	TextureResource& _ordinaryBulletTexture;
	TextureResource& _rocketTexture;
	const float _bulletDeflection;

	Token_t _bulletCreation;
	Token_t _rocketCreation;

	RocketOutOfBoundsEvent _rocketOutOfBoundsEvent;

public:
	Token_t deleteRocket;
	Token_t deleteBullet;

	BulletManager(TextureResource& ordinaryBulletTexture, TextureResource& rocketTexture);
	~BulletManager();
	std::vector<OrdinaryBullet*> bullets;
	std::vector<Rocket*> rockets;

	void RocketOutOfBoundsHandler(const Event& event);
	void DeleteBullet(OrdinaryBullet* bullet);
	void DeleteRocket(Rocket* rocket);

	void Update(const sf::Time& deltaTime);
};

