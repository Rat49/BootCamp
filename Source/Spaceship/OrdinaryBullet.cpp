#include "OrdinaryBullet.h"

const float PI_F = 3.14159265358979f;

OrdinaryBullet::OrdinaryBullet()
	: _speedValue(200.0f)
	, _ordinaryBulletSprite()
	, _bulletTexture()
	//,_ordinaryBulletAnimation()
{
	Add();
	_zOrder = 2;
	_life = false;
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

void OrdinaryBullet::Init(sf::Vector2f position, const  sf::Vector2f bulletDirection, sf::Texture& bulletTexture)
{
	_life = true;
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
	if (GetLifeStatus())
	{
		window.draw(_ordinaryBulletSprite);
	}
}

void OrdinaryBullet::Update(sf::Time& deltaTime)
{
	RigidBody::Update(deltaTime.asSeconds());

	_ordinaryBulletSprite.setPosition(GetCoordinates());
	//_ordinaryBulletAnimation->Update(deltaTime);

	if (_ordinaryBulletSprite.getPosition().x >= WindowResolution::_W || _ordinaryBulletSprite.getPosition().x < 0 
	  || _ordinaryBulletSprite.getPosition().y > WindowResolution::_H || _ordinaryBulletSprite.getPosition().y < 0)
	{
		_life = false;
	}
}

void OrdinaryBullet::Reset()
{
	//_ordinaryBulletAnimation->Reset();

	_life = false;
	_ordinaryBulletSprite.setOrigin(0, 0);
	_ordinaryBulletSprite.setPosition(0, 0);
	_ordinaryBulletSprite.setRotation(0);
	SetSpeed(sf::Vector2f(0, 0));
}

bool OrdinaryBullet::GetLifeStatus() const
{
	return _life;
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
