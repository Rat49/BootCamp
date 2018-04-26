#include "OrdinaryBullet.h"

OrdinaryBullet::OrdinaryBullet()
	: _speedValuePixelsPerSecond(200.0f)
	, _ordinaryBulletSprite()
	, _bulletTexture()
	, _bulletScale(1.0f, 1.0f)
{
	_zOrder = 4;
}

void OrdinaryBullet::Init(const sf::Vector2f& position, const sf::Vector2f& bulletDirection, sf::Texture& bulletTexture)
{
	AddToDrawableManager();
	
	_bulletScale = sf::Vector2f(0.5f, 0.5f);
	_bulletTexture = &bulletTexture;
	_ordinaryBulletSprite.setTexture(*_bulletTexture);
	_ordinaryBulletSprite.setScale(_bulletScale);
	_ordinaryBulletSprite.setOrigin(sf::Vector2f(_bulletTexture->getSize().x / 2.0f, _bulletTexture->getSize().y / 2.0f));
	float degreeAngle = RadiansToDegrees(std::atan(bulletDirection.x / -bulletDirection.y));
	if (bulletDirection.y > 0)
		degreeAngle += 180.0f;
	
	_ordinaryBulletSprite.setRotation(degreeAngle);
	SetSpeed(bulletDirection * _speedValuePixelsPerSecond);
	//???
	SetCoordinates(sf::Vector2f(position.x, position.y));
}

const sf::Sprite* OrdinaryBullet::GetSprite()
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

void OrdinaryBullet::AddToDrawableManager()
{
	DrawableManager::getInstance().AddDrawableObject(this);
}

int OrdinaryBullet::GetZOrder() const
{
	return _zOrder;
}
