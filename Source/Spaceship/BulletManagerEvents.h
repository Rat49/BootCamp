#pragma once
#include "SFML\Graphics.hpp"
#include "Event.h"
#include "OrdinaryBullet.h"
#include "Rocket.h"

class CreateBulletEvent : public Event
{
public:
	sf::Vector2f _position;
	sf::Vector2f _direction;

	CreateBulletEvent(sf::Vector2f position, sf::Vector2f direction);
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

	CreateRocketEvent(sf::Vector2f position, sf::Vector2f direction);
};

class DeleteRocketEvent : public Event
{
public:
	Rocket* _deletedRocket;
};