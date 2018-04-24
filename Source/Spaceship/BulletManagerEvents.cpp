#include "BulletManagerEvents.h"

CreateBulletEvent::CreateBulletEvent(sf::Vector2f position, sf::Vector2f direction)
{
	_position = position;
	_direction = direction;
}

CreateRocketEvent::CreateRocketEvent(sf::Vector2f position, sf::Vector2f direction)
{
	_position = position;
	_direction = direction;
}
