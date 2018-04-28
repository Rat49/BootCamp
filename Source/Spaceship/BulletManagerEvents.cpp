#include "BulletManagerEvents.h"

CreateBulletEvent::CreateBulletEvent(const sf::Vector2f& position, const sf::Vector2f& direction, bool isColliderVisible)
{
	_position = position;
	_direction = direction;
	_isColliderVisible = isColliderVisible;
}

CreateRocketEvent::CreateRocketEvent(const sf::Vector2f& position, const sf::Vector2f& direction, bool isColliderVisible)
{
	_position = position;
	_direction = direction;
	_isColliderVisible = isColliderVisible;
}


