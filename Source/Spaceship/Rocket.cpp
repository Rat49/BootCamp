#include "DrawableManager.h"
#include "Rocket.h"

Rocket::Rocket()
	: _speedValue(50.6f),
	_rocketSprite(),
	_rocketAnimation()
{
	_zOrder = 1;
}

Rocket::~Rocket()
{
	//unsub event 
}

void Rocket::Init(const sf::Vector2f position, const  sf::Vector2f rocketDirection, ImageSequenceResource& rocketAnimationImseq)
{
	*_rocketAnimationImseq = rocketAnimationImseq;
	_rocketAnimation->Init(_rocketSprite, rocketAnimationImseq, true);

	Add();

	_rocketAnimation->Start();
	_rocketAnimation->GetSprite()->setOrigin(sf::Vector2f(_rocketAnimation->GetWidth() / 2.0f, _rocketAnimation->GetHeight() / 2.0f));
	_rocketAnimation->GetSprite()->setPosition(position);

	SetSpeed(rocketDirection * _speedValue);
	_speedDelayTime = sf::seconds(0.0f);
	SetCoordinates(position);
}

sf::Sprite* Rocket::GetSprite()
{
	return _rocketAnimation->GetSprite();
}

void Rocket::Draw(sf::RenderWindow & window)
{
	window.draw(*(_rocketAnimation->GetSprite()));
}

void Rocket::Update(sf::Time deltaTime)
{
	RigidBody::Update(deltaTime.asSeconds());
	
	_speedDelayTime += deltaTime;
	if (_speedDelayTime.asSeconds() > 2.0f)
	{
		SetSpeed(GetSpeed() + sf::Vector2f(10, 10));
	}

	_rocketAnimation->GetSprite()->setPosition(GetCoordinates());
	_rocketAnimation->Update(deltaTime);
}

void Rocket::Reset()
{
	_rocketAnimation->Reset();
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
