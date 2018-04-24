#include "OrdinaryBullet.h"

const float PI_F = 3.14159265358979f;

OrdinaryBullet::OrdinaryBullet()
	: _speedValue(200.0f)
	, _ordinaryBulletSprite()
	, _bulletTexture()
{
	_zOrder = 4;
}

void OrdinaryBullet::Init(sf::Vector2f position, const  sf::Vector2f bulletDirection, sf::Texture& bulletTexture)
{
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

void OrdinaryBullet::Update(const sf::Time& deltaTime)
{
	RigidBody::Update(deltaTime.asSeconds());

	_ordinaryBulletSprite.setPosition(GetCoordinates());
}

void OrdinaryBullet::Reset()
{
	_ordinaryBulletSprite.setOrigin(0, 0);
	_ordinaryBulletSprite.setPosition(0, 0);
	_ordinaryBulletSprite.setRotation(0);
	SetSpeed(sf::Vector2f(0, 0));
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
