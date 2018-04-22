#include "Rocket.h"

const float PI_F = 3.14159265358979f;

Rocket::Rocket()
	: _speedValue(200.0f)
	, _rocketSprite()
	, _rocketTexture()
	, _speedDelayTime(sf::seconds(1.0f))
	, _deltaSpeedValue(600.0f)
	//,_rocketAnimation()
{
	Add();
	_zOrder = 2;	
	_life = false;
}

Rocket::~Rocket()
{
	//unsub event 
}

//void Rocket::Init(const sf::Vector2f position, const  sf::Vector2f rocketDirection, ImageSequenceResource& rocketAnimationImseq)
//{
//	*_rocketAnimationImseq = rocketAnimationImseq;
//	_rocketAnimation->Init(&_rocketSprite, &rocketAnimationImseq, true);
//
//	Add();
//
//	_rocketAnimation->Start();
//	_rocketAnimation->GetSprite()->setOrigin(sf::Vector2f(_rocketAnimation->GetWidth() / 2.0f, _rocketAnimation->GetHeight() / 2.0f));
//	_rocketAnimation->GetSprite()->setPosition(position);
//
//	SetSpeed(rocketDirection * _speedValue);
//	_speedDelayTime = sf::seconds(0.0f);
//	SetCoordinates(position);
//}

void Rocket::Init(sf::Vector2f position, const sf::Vector2f rocketDirection, sf::Texture& rocketTexture)
{
	_life = true;
	_direction = rocketDirection;
	_rocketTexture = &rocketTexture;
	_rocketSprite.setTexture(*_rocketTexture);
	_rocketSprite.setOrigin(sf::Vector2f(_rocketTexture->getSize().x / 2.0f, _rocketTexture->getSize().y / 2.0f));
	float angle = std::atan(_direction.x / -_direction.y) * 180.0f / PI_F;
	if (_direction.y > 0)
		angle += 180.0f;

	_rocketSprite.setRotation(angle);
	
	SetSpeed(rocketDirection * _speedValue);
	_timeAfterShot = sf::seconds(0.0f);
	SetCoordinates(sf::Vector2f(position.x + rocketDirection.x * _rocketTexture->getSize().y / 2.0f, position.y + rocketDirection.y * _rocketTexture->getSize().y / 2.0f));
}

sf::Sprite* Rocket::GetSprite()
{
	return &_rocketSprite;
}

void Rocket::Draw(sf::RenderWindow& window)
{
	if (GetLifeStatus())
	{
		window.draw(_rocketSprite);
	}
}

void Rocket::Update(sf::Time& deltaTime)
{
	RigidBody::Update(deltaTime.asSeconds());
	
	_timeAfterShot += deltaTime;
	if (_timeAfterShot.asSeconds() > _speedDelayTime.asSeconds())
	{
		SetSpeed(_direction * (_speedValue + _deltaSpeedValue));
	}

	if (_rocketSprite.getPosition().x >= WindowResolution::_W || _rocketSprite.getPosition().x < 0
		|| _rocketSprite.getPosition().y > WindowResolution::_H || _rocketSprite.getPosition().y < 0)
	{
		_life = false;
	}

	_rocketSprite.setPosition(GetCoordinates());
	//_rocketAnimation->Update(deltaTime);
}

void Rocket::Reset()
{
	//_rocketAnimation->Reset();

	_life = false;

	_rocketSprite.setOrigin(0, 0);
	_rocketSprite.setPosition(0, 0);
	_rocketSprite.setRotation(0);
	_direction = sf::Vector2f(0, 0);
	_timeAfterShot = sf::seconds(0);
	SetSpeed(sf::Vector2f(0, 0));
}

bool Rocket::GetLifeStatus() const
{
	return _life;
}

void Rocket::Add()
{
	DrawableManager::getInstance()._drawableObjects.push_back(this);
	DrawableManager::getInstance().SortDrawableVector();
}

int Rocket::GetZOrder() const
{
	return _zOrder;
}
