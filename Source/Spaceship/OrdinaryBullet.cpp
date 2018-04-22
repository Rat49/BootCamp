#include "OrdinaryBullet.h"

const float PI_F = 3.14159265358979f;

OrdinaryBullet::OrdinaryBullet()
	: _speedValue(200.0f)
	, _ordinaryBulletSprite()
	, _bulletTexture()
	//,_ordinaryBulletAnimation()
{
	_zOrder = 2;
}

OrdinaryBullet::~OrdinaryBullet()
{
	//unsub event
}

//void OrdinaryBullet::Init(const sf::Vector2f position,const  sf::Vector2f bulletDirection, ImageSequenceResource& bulletAnimationImseq)
//{
//	_bulletAnimationImseq = &bulletAnimationImseq;
//
//	
//	_ordinaryBulletAnimation->Init(&_ordinaryBulletSprite, &bulletAnimationImseq, true);
//	
//	Add();
//
//	_ordinaryBulletAnimation->Start();
//
//	float spriteHeight = _ordinaryBulletAnimation->GetHeight();
//	float spriteWidth = _ordinaryBulletAnimation->GetWidth();
//	_ordinaryBulletAnimation->GetSprite()->setOrigin(sf::Vector2f(_ordinaryBulletAnimation->GetWidth() / 2.0f, _ordinaryBulletAnimation->GetHeight() / 2.0f));
//
//	SetSpeed(bulletDirection * _speedValue);
//	SetCoordinates(sf::Vector2f(position.x + bulletDirection.x * spriteHeight / 2.0f, position.y + bulletDirection.y * spriteHeight / 2.0f));

  //_ordinaryBulletSprite() = _ordinaryBulletAnimation->GetSprite();
//}

void OrdinaryBullet::Init(sf::Sprite& ordinaryBulletSprite, sf::Vector2f position, const  sf::Vector2f bulletDirection, sf::Texture& bulletTexture)
{
	_ordinaryBulletSprite = ordinaryBulletSprite;
	Add();
	_bulletTexture = &bulletTexture;
	_ordinaryBulletSprite.setTexture(*_bulletTexture);
	_ordinaryBulletSprite.setOrigin(sf::Vector2f(_bulletTexture->getSize().x / 2.0f, _bulletTexture->getSize().y / 2.0f));
	float angle = std::atan(bulletDirection.x / -bulletDirection.y) * 180.0f / PI_F;	
	if (bulletDirection.y > 0)
		angle += 180.0f;

	_ordinaryBulletSprite.setRotation(angle);

	SetSpeed(bulletDirection * _speedValue);
	SetCoordinates(sf::Vector2f(position.x + bulletDirection.x * _bulletTexture->getSize().y / 2.0f, position.y + bulletDirection.y * _bulletTexture->getSize().y / 2.0f));
}

sf::Sprite* OrdinaryBullet::GetSprite()
{
	return &_ordinaryBulletSprite;
}

void OrdinaryBullet::Draw(sf::RenderWindow& window)
{
	window.draw(_ordinaryBulletSprite);
}

void OrdinaryBullet::Update(sf::Time& deltaTime)
{
	RigidBody::Update(deltaTime.asSeconds());

	_ordinaryBulletSprite.setPosition(GetCoordinates());
	//_ordinaryBulletAnimation->Update(deltaTime);
}

void OrdinaryBullet::Reset()
{
	//_ordinaryBulletAnimation->Reset();

	_ordinaryBulletSprite.setTexture(sf::Texture::Texture());
	_ordinaryBulletSprite.setOrigin(sf::Vector2f(0.0f, 0.0f));
	_ordinaryBulletSprite.setPosition(sf::Vector2f(0.0f, 0.0f));
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
