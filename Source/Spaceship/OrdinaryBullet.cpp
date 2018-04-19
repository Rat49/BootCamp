#include "OrdinaryBullet.h"
#include "DrawableManager.h"
#include <iostream>

OrdinaryBullet::OrdinaryBullet(sf::Vector2f position, sf::Vector2f bulletDirection, AnimationPlayer* bulletAnimation)
	: _ordinaryBulletAnimation(bulletAnimation)
	, _speedValue(50.6f)
{
	_zOrder = 1;
	_ordinaryBulletAnimation->GetSprite()->setPosition(position);

	SetSpeed(bulletDirection * _speedValue);
	SetCoordinates(position);

	std::cout << "Bullet direction" << bulletDirection.x << " " << bulletDirection.y << std::endl;
	Add();

	_ordinaryBulletAnimation->Start();

}

OrdinaryBullet::~OrdinaryBullet()
{
	//unsub event
}

void OrdinaryBullet::Draw(sf::RenderWindow & window)
{
	window.draw(*(_ordinaryBulletAnimation->GetSprite()));
}

void OrdinaryBullet::Update(sf::Time deltaTime)
{

	RigidBody::Update(deltaTime.asSeconds());

	//behind the screen???
	_ordinaryBulletAnimation->GetSprite()->setPosition(GetCoordinates());
	_ordinaryBulletAnimation->Update(deltaTime);

	//std::cout << _ordinaryBulletAnimation.GetSprite()->getPosition().x << " " << _ordinaryBulletAnimation.GetSprite()->getPosition().y << std::endl;
}

void OrdinaryBullet::Add()
{
	DrawableManager::getInstance()._drawableObjects.push_back(this);
	DrawableManager::getInstance().SortDrawableVector();
}

int OrdinaryBullet::GetZOrder() const
{
	return _zOrder;
}
