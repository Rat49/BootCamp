#include "OrdinaryBullet.h"
#include "DrawableManager.h"

OrdinaryBullet::OrdinaryBullet(sf::Vector2f position, sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation)
	: Bullet(position, bulletDirection, 10.0f, 1.0f)
	, _ordinaryBulletAnimation(bulletAnimation)
	, _speedValue(25.6f)
{
	_zOrder = 1;
	
	SetSpeed(bulletDirection * _speedValue);
	//Add();
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
	
	//behind the screen???
	
	_ordinaryBulletAnimation.Update(deltaTime);
}

void OrdinaryBullet::Add()
{
	DrawableManager::_drawableObjects.push_back(this);
}

int OrdinaryBullet::GetZOrder() const
{
	return _zOrder;
}
