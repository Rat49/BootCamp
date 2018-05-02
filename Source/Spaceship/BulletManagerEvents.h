#pragma once
#include "Event.h"
#include "SFML\Graphics.hpp"

class OrdinaryBullet;
class Rocket;

class CreateBulletEvent : public Event
{
public:
	sf::Vector2f _position;
	sf::Vector2f _direction;
	bool _isColliderVisible;

	CreateBulletEvent(const sf::Vector2f& position, const sf::Vector2f& direction, bool _isColliderVisible);
};

class DeleteBulletEvent : public Event
{
public:
	OrdinaryBullet* _deletedBullet;
};

class DeleteRocketEvent : public Event
{
public:
	Rocket * deletedRocket;
};

class CreateRocketEvent : public Event
{
public:
	sf::Vector2f _position;
	sf::Vector2f _direction;
	bool _isColliderVisible;

	CreateRocketEvent(const sf::Vector2f& position, const sf::Vector2f& direction, bool _isColliderVisible);
};

class RocketOutOfBoundsEvent : public Event
{
public:
	Rocket* _deletedRocket;
};
