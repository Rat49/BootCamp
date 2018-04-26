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
	
	SetRadius(5);
	Bullet::_damage = 400;
	_bulletScale = sf::Vector2f(0.3f, 0.3f);
	_bulletTexture = &bulletTexture;
	_ordinaryBulletSprite.setTexture(*_bulletTexture);
	_ordinaryBulletSprite.setScale(_bulletScale);
	_ordinaryBulletSprite.setOrigin(sf::Vector2f(_bulletTexture->getSize().x / 2.0f, _bulletTexture->getSize().y / 2.0f));
	float degreeAngle = RadiansToDegrees(std::atan(bulletDirection.x / -bulletDirection.y));
	if (bulletDirection.y > 0)
		degreeAngle += 180.0f;
	
	_ordinaryBulletSprite.setRotation(degreeAngle);
	SetSpeed(bulletDirection * _speedValuePixelsPerSecond);
	SetCoordinates(sf::Vector2f(position.x, position.y));
}

const sf::Sprite* OrdinaryBullet::GetSprite()
{
	return &_ordinaryBulletSprite;
}

void OrdinaryBullet::Draw(sf::RenderWindow& window)
{
	sf::CircleShape physicsShape(GetRadius());
	auto t = GetRadius();
	physicsShape.setPosition(GetCoordinates());
	//physicsShape.setOrigin(sf::Vector2f{ GetRadius(), GetRadius() });
	physicsShape.setOutlineColor(sf::Color(255, 255, 255, 255));
	physicsShape.setFillColor(sf::Color::Transparent);
	physicsShape.setOutlineThickness(1);

	window.draw(physicsShape);
	sf::CircleShape circleCenter(1);
	circleCenter.setPosition(GetX() + GetRadius(),
		GetY() + GetRadius());
	circleCenter.setRadius(1.f);
	circleCenter.setFillColor(sf::Color::Green);
	window.draw(circleCenter);
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
