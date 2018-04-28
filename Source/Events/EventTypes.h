#pragma once
using EventID_t = int;

enum EventTypes : EventID_t
{
	firstEventID = 1,
	secondEventID,
    resizeWindowEventID,
	debugCommandManagerEventID,
	debugConsoleKeyEventID,
	loggerMessageEventID,
	collisionEventID,
	collisionEventBetweenAsteroidsID,
	collisionEventBetweenAsteroidAndBulletID,
	collisionEventBetweenAsteroidAndRocketID,
	collisionEventBetweenAsteroidAndSpaceshipID,
	rocketOutOfBoundsEventID,
	createBulletEventID,
	createRocketEventID,
	collisionEventBetweenAmmunitionAndAsteroidId,
	collisionEventBetweenAmmunitionAndSpaceshipId,
	collisionEventBetweenAmmunitionAndBulletId,
	collisionEventBetweenAmmunitionAndRocketId,
	spaceshipRespawnEventID,
	gameOverEventID
};
