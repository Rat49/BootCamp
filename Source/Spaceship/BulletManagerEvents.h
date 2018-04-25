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

	CreateBulletEvent(const sf::Vector2f& position, const sf::Vector2f& direction);
};

class DeleteBulletEvent : public Event
{
public:
	OrdinaryBullet* _deletedBullet;
};

class CreateRocketEvent : public Event
{
public:
	sf::Vector2f _position;
	sf::Vector2f _direction;

	CreateRocketEvent(const sf::Vector2f& position, const sf::Vector2f& direction);
};

class DeleteRocketEvent : public Event
{
public:
	Rocket* _deletedRocket;
};