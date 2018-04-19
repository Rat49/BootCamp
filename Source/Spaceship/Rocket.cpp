#include "DrawableManager.h"
#include "Rocket.h"

Rocket::Rocket(sf::Vector2f rocketPosition, sf::Vector2f rocketDirection, AnimationPlayer& rocketAnimation)
	: _rocketAnimation(rocketAnimation)
	, _speedValue(14.90f)
{
	_zOrder = 1;
	_speedDelayTime = sf::seconds(0.0f);

	SetSpeed(rocketDirection * _speedValue);
}

Rocket::~Rocket()
{
	//unsub event 
}

void Rocket::Add()
{
	DrawableManager::getInstance()._drawableObjects.push_back(this);
}

int Rocket::GetZOrder() const
{
	return _zOrder;
}

void Rocket::Draw(sf::RenderWindow & window)
{
	window.draw(*(_rocketAnimation.GetSprite()));
}

void Rocket::Update(sf::Time deltaTime)
{
	_speedDelayTime += deltaTime;

	if (_speedDelayTime.asSeconds() > 2.0f)
	{
		SetSpeed(GetSpeed() + sf::Vector2f(10,10));
	}
	
	RigidBody::Update(deltaTime.asSeconds());

	_rocketAnimation.Update(deltaTime);
}
