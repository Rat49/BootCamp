#include "Rocket.h"
#include "CollisionEvent.h"


Rocket::Rocket()
	: _speedValuePixelsPerSecond(200.0f)
	, _rocketSprite()
	, _rocketTexture()
	, _speedDelayTime(sf::seconds(1.0f))
	, _deltaSpeedValue(600.0f)
	, _rocketScale(1.0f, 1.0f)
	, _halfSpriteLength(0.0f)
{
	_zOrder = 3;	
	isAlive = false;
}

void Rocket::Init(const sf::Vector2f& position, const sf::Vector2f& rocketDirection, sf::Texture& rocketTexture, RocketParticle& rocketParticle, bool isColliderVisible)
{
	AddToDrawableManager();
	SetColliderVisible(isColliderVisible);
	_isAlive = true;
	_rocketScale = sf::Vector2f(0.5f, 0.5f);
	_direction = rocketDirection;
	_rocketTexture = &rocketTexture;
	_rocketSprite.setTexture(*_rocketTexture);
	_rocketSprite.setScale(_rocketScale);
	_rocketSprite.setOrigin(sf::Vector2f(_rocketTexture->getSize().x / 2.0f , 
		_rocketTexture->getSize().y / 2.0f ));
	float degreeAngle = RadiansToDegrees(std::atan(_direction.x / -_direction.y));
	if (_direction.y > 0)
		degreeAngle += 180.0f;
	
	SetRadius(10);

	sf::Vector2f rigidCoordinates = RigidBody::GetCoordinates();
	_halfSpriteLength = GetLenght(sf::Vector2f(_rocketTexture->getSize())) / 2.0f;

	_rocketSprite.setRotation(degreeAngle);

	_rocketParticle = &rocketParticle;
	_rocketParticle->Play();

	_rocketParticle->SetPosition(sf::Vector2f(position.x + rocketDirection.x * _rocketTexture->getSize().x / 2.0f, 
		position.y + rocketDirection.y * _rocketTexture->getSize().y / 2.0f));
	_rocketParticle->SetVelocity(rocketDirection * _speedValuePixelsPerSecond);
	_rocketParticle->AddForces();
	
	SetSpeed(rocketDirection * _speedValuePixelsPerSecond);
	_timeAfterShot = sf::Time::Zero;
	SetCoordinates(sf::Vector2f(position.x, position.y));
}

const sf::Sprite* Rocket::GetSprite()
{
	return &_rocketSprite;
}

const float Rocket::GetHalfSpriteLength()
{
	return _halfSpriteLength;
}

void Rocket::Draw(sf::RenderWindow& window)
{
	window.draw(_rocketSprite);

	if (IsColliderVisible())
	{
		sf::CircleShape physicsShape(GetRadius());
		physicsShape.setPosition(GetCoordinates());
		physicsShape.setOutlineColor(sf::Color(255, 255, 255, 255));
		physicsShape.setFillColor(sf::Color::Transparent);
		physicsShape.setOutlineThickness(1);

		window.draw(physicsShape);

		sf::CircleShape circleCenter(1);
		circleCenter.setPosition(GetX() + GetRadius(),
			GetY() + GetRadius());
		circleCenter.setRadius(1.0f);
		circleCenter.setFillColor(sf::Color::Green);

		window.draw(circleCenter);
	}
}

void Rocket::Update(const sf::Time& deltaTime)
{
	
		RigidBody::Update(deltaTime.asSeconds());
		_rocketParticle->Update(deltaTime);

		_timeAfterShot += deltaTime;
		if (_timeAfterShot.asSeconds() > _speedDelayTime.asSeconds())
		{
			_rocketParticle->SetVelocity(_direction * (_speedValuePixelsPerSecond + _deltaSpeedValue));
			SetSpeed(_direction * (_speedValuePixelsPerSecond + _deltaSpeedValue));
		}

		/*if (_rocketSprite.getPosition().x >= WindowResolution::_W || _rocketSprite.getPosition().x < 0
			|| _rocketSprite.getPosition().y > WindowResolution::_H || _rocketSprite.getPosition().y < 0)
		{
			_rocketParticle->Stop();
			if (_rocketParticle->IsEnd())
				_isAlive = false;
		}*/

		sf::Vector2f rigidCoordinates = RigidBody::GetCoordinates();
		_rocketSprite.setPosition(rigidCoordinates.x + _rocketSprite.getLocalBounds().width / 3,
			rigidCoordinates.y + _rocketSprite.getLocalBounds().height / 3);
		_rocketParticle->SetPosition(sf::Vector2f( GetCoordinates().x + GetRadius(), GetCoordinates().y + GetRadius()));
		_rocketSprite.setPosition(GetCoordinates().x + GetRadius(), GetCoordinates().y + GetRadius());
	
	
}

void Rocket::Reset()
{
	isAlive = true;
	_rocketSprite.setOrigin(0, 0);
	_rocketSprite.setPosition(0, 0);
	_rocketSprite.setRotation(0);
	_direction = sf::Vector2f(0, 0);
	_timeAfterShot = sf::seconds(0);
	SetSpeed(sf::Vector2f(0, 0));
}


bool Rocket::GetLifeStatus() const
{
	return isAlive;
}



void Rocket::OnCollisionHandler(const Event& cEvent)
{
	const CollisionEventBetweenAsteroidAndRocket &collisionEvent = dynamic_cast<const CollisionEventBetweenAsteroidAndRocket&>(cEvent);

	SetRadius(50);
	SetSpeed(sf::Vector2f(0, 0));
}


void Rocket::AddToDrawableManager()
{
	_tokens[collisionEventBetweenAsteroidAndRocketID] = Dispatcher::getInstance().Connect(EventTypes::collisionEventBetweenAsteroidAndRocketID,
		[&](const Event& event)
	{
		OnCollisionHandler(event);
	});

	DrawableManager::getInstance().AddDrawableObject(this);
}

int Rocket::GetZOrder() const
{
	return _zOrder;
}
