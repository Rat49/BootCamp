#pragma once
#include "EventSystem.h"
#include "BulletManagerEvents.h"
#include "Pool.h"
#include "OrdinaryBullet.h"
#include "Rocket.h"
#include "ResourceManager.h"
#include "SFML\Graphics.hpp"

class BulletManager final 
{
public:
	const int _totalBulletCount;
	const int _totalRocketCount;
	Pool<OrdinaryBullet> _ordinaryBulletStorage;
	Pool<Rocket> _rocketStorage;
	std::vector<OrdinaryBullet*> _bullets;
	std::vector<Rocket*> _rockets;	
	TextureResource& _ordinaryBulletTexture;
	TextureResource& _rocketTexture;
	float _bulletDeflection;

	Token_t _bulletDeletion;
	Token_t _rocketDeletion;
	Token_t _bulletCreation;
	Token_t _rocketCreation;

	BulletManager(TextureResource& ordinaryBulletTexture, TextureResource& rocketTexture);
	~BulletManager();
	void CreateBullet(const Event& event);
	void DeleteBullet(const Event& event);
	void CreateRocket(const Event& event);
	void DeleteRocket(const Event& event);
	void Update(sf::Time deltaTime);
	sf::Vector2f DeflectBullets(float angle, sf::Vector2f direction) const;
};

