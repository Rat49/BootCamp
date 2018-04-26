#include "BulletManagerEvents.h"

CreateBulletEvent::CreateBulletEvent(const sf::Vector2f& position, const sf::Vector2f& direction)
{
	_position = position;
	_direction = direction;
}

CreateRocketEvent::CreateRocketEvent(const sf::Vector2f& position, const sf::Vector2f& direction)
{
	_position = position;
	_direction = direction;
}

DeleteBulletEvent::DeleteBulletEvent(OrdinaryBullet* deletedBullet)
{
	_deletedBullet = deletedBullet;
}

DeleteRocketEvent::DeleteRocketEvent(Rocket* deletedRocket)
{
	_deletedRocket = deletedRocket;
}