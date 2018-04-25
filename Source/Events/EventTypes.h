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
	createBulletEventID,
	createRocketEventID,
	deleteRocketEventID,
	deleteBulletEventID,
};
