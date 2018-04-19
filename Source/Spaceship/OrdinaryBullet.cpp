#include "OrdinaryBullet.h"
#include "DrawableManager.h"

OrdinaryBullet::OrdinaryBullet(sf::Vector2f bulletPosition, sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation)
	: Bullet(bulletPosition, bulletDirection, 10.0f, 1.0f)
	, _ordinaryBulletAnimation(bulletAnimation)
	, _speedValue(25.6f)
{
	_zOrder = 1;
	
	SetSpeed(bulletDirection * _speedValue);
}

OrdinaryBullet::~OrdinaryBullet()
{
	//unsub event
}

void OrdinaryBullet::Draw(sf::RenderWindow & window)
{
	window.draw(*(_ordinaryBulletAnimation.GetSprite()));
}

void OrdinaryBullet::Update(sf::Time deltaTime)
{
	RigidBody::Update(deltaTime.asSeconds());
	
	_ordinaryBulletAnimation.Update(deltaTime);
}

void OrdinaryBullet::Add()
{
	DrawableManager::getInstance()._drawableObjects.push_back(this);
}

int OrdinaryBullet::GetZOrder() const
{
	return _zOrder;
}
