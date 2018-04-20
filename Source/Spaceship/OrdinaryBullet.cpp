#include "DrawableManager.h"
#include "OrdinaryBullet.h"

OrdinaryBullet::OrdinaryBullet()
	: _speedValue(50.6f),
	_ordinaryBulletSprite(),
	_ordinaryBulletAnimation()
{
	_zOrder = 1;
}

OrdinaryBullet::~OrdinaryBullet()
{
	//unsub event
}

void OrdinaryBullet::Init(const sf::Vector2f position,const  sf::Vector2f bulletDirection, ImageSequenceResource& bulletAnimationImseq)
{
	_bulletAnimationImseq = &bulletAnimationImseq;

	
	_ordinaryBulletAnimation->Init(_ordinaryBulletSprite, bulletAnimationImseq, true);
	
	Add();

	_ordinaryBulletAnimation->Start();

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

	_ordinaryBulletAnimation->GetSprite()->setPosition(GetCoordinates());
	_ordinaryBulletAnimation->Update(deltaTime);
}

void OrdinaryBullet::Reset()
{
	//_ordinaryBulletAnimation->Reset();
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
