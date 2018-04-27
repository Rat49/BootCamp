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
	//bulletOutOfBoundsEventID,
	rocketOutOfBoundsEventID,
	createBulletEventID,
	createRocketEventID,
	//deleteRocketEventID,
	deleteBulletEventID,
	collisionEventBetweenAmmunitionAndSpaceshipId,
	collisionEventBetweenAmmunitionAndBulletId,
	collisionEventBetweenAmmunitionAndRocketId,
	spaceshipRespawnEventID,
	gameOverEventID
};
