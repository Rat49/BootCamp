#include "DrawableManager.h"
#include "OrdinaryBullet.h"
#include <iostream>

OrdinaryBullet::OrdinaryBullet(sf::Vector2f position, sf::Vector2f bulletDirection, ImageSequenceResource& bulletAnimationImseq)
	: _bulletAnimationImseq(bulletAnimationImseq)
	, _speedValue(150.6f)
{
	_zOrder = 1;

	_ordinaryBulletSprite = new sf::Sprite();
	_ordinaryBulletAnimation = new AnimationPlayer(*_ordinaryBulletSprite, _bulletAnimationImseq, true);

	Init(position, bulletDirection);
	//=============================================================================================
	std::cout << "Bullet direction" << bulletDirection.x << " " << bulletDirection.y << std::endl;
	//=============================================================================================

	Add();

	_ordinaryBulletAnimation->Start();
}

OrdinaryBullet::~OrdinaryBullet()
{
	//unsub event
}

void OrdinaryBullet::Init(sf::Vector2f position, sf::Vector2f bulletDirection)
{
	float spriteHeight = _ordinaryBulletAnimation->GetHeight();
	float spriteWidth = _ordinaryBulletAnimation->GetWidth();
	_ordinaryBulletAnimation->GetSprite()->setOrigin(sf::Vector2f(_ordinaryBulletAnimation->GetWidth() / 2.0f, _ordinaryBulletAnimation->GetHeight() / 2.0f));

	SetSpeed(bulletDirection * _speedValue);
	SetCoordinates(sf::Vector2f(position.x + bulletDirection.x * spriteHeight / 2.0f, position.y + bulletDirection.y * spriteHeight / 2.0f));
}

sf::Sprite* OrdinaryBullet::GetSprite()
{
	return _ordinaryBulletAnimation->GetSprite();
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
}

void OrdinaryBullet::Reset()
{
	_ordinaryBulletAnimation->Reset();
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
