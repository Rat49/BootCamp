#include "OrdinaryBullet.h"

OrdinaryBullet::OrdinaryBullet(sf::Vector2f bulletDirection, AnimationPlayer& bulletAnimation)
	:_ordinaryBulletAnimation(bulletAnimation)
{
	//body *= _speed
}

OrdinaryBullet::~OrdinaryBullet()
{
	//unsub event
}

void OrdinaryBullet::Update(sf::Time deltaTime)
{
	//body update

	//behind the screen
	
	_ordinaryBulletAnimation.Update(deltaTime);
}

void OrdinaryBullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw((*_ordinaryBulletAnimation.GetSprite()),states);
}