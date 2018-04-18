#include "OrdinaryBullet.h"

OrdinaryBullet::OrdinaryBullet(sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation)
	:_ordinaryBulletAnimation(bulletAnimation)
{
	_zOrder = 1;
	SetSpeed(bulletDirection * _speedValue);
}

OrdinaryBullet::~OrdinaryBullet()
{
	//unsub event
}

void OrdinaryBullet::Update(sf::Time deltaTime)
{
	
	RigidBody::Update(deltaTime.asSeconds());
	
	//behind the screen???
	
	_ordinaryBulletAnimation.Update(deltaTime);
}

void OrdinaryBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw((*_ordinaryBulletAnimation.GetSprite()),states);
}

void OrdinaryBullet::setZOrder(int zOrder)
{
	this->_zOrder = zOrder;
}

int OrdinaryBullet::getZOrder() const
{
	return _zOrder;
}
