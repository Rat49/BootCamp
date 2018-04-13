#include "Physics.h"
#include "EventSystem.h"
#include "CollisionEvent.h"

CollisionEvent::CollisionEvent() {

}

CollisionEvent::~CollisionEvent() {

}
void CollisionEvent::setObjs(RigidBody &o1, RigidBody &o2) {
	obj1 = o1;
	obj2 = o2;
}

constexpr size_t numOfObjects = 4;
void MainLoop(RigidBody *RigidBodysFunc) {
	sf::Clock clock;
	sf::Time deltaTime;
		
	sf::RenderWindow app(sf::VideoMode(W, H), "Asteroids!");

	sf::CircleShape circles[numOfObjects];

	CollisionEvent collisionEvent;
	Dispatcher& dispatcher = Dispatcher::getInstance();

	for (int i = 0; i < numOfObjects; ++i) {
		circles[i].setRadius(RigidBodysFunc[i].GetRadius());
		circles[i].setPosition(RigidBodysFunc[i].GetX(), RigidBodysFunc[i].GetY());
	}

	while (app.isOpen()) {
		deltaTime = clock.restart();
		float deltaSeconds = deltaTime.asSeconds();

		sf::Event event;

		while (app.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				app.close();
			}
		}
		for (int i = 0; i < numOfObjects; ++i)
			circles[i].setFillColor(sf::Color::White);

		for (int i = 0; i < numOfObjects; ++i) {
			for (int j = 0; j < numOfObjects; ++j) {
				if (i != j) {
					if (Collided(RigidBodysFunc[i], RigidBodysFunc[j])) {
						circles[i].setFillColor(sf::Color::Red);
						circles[j].setFillColor(sf::Color::Red);
						collisionEvent.setObjs(RigidBodysFunc[i], RigidBodysFunc[j]);
						dispatcher.Send(collisionEvent, firstEventID);
						ResolveCollision(RigidBodysFunc[i], RigidBodysFunc[j]);
					}
				}
			}
		}

		for (int i = 0; i < numOfObjects; ++i) {
			RigidBodysFunc[i].Update(deltaSeconds);
			circles[i].setPosition(RigidBodysFunc[i].GetX(), RigidBodysFunc[i].GetY());
		}

		app.clear();
		for (int i = 0; i < numOfObjects; ++i) {
			app.draw(circles[i]);
		}
		app.display();
	}
}

void Test() {
	RigidBody* RigidBodys = new RigidBody[numOfObjects];
	//RandomFill(RigidBodys, numOfObjects);

	for (int i = 0; i < numOfObjects / 2; i++)
	{
		const int idx = i * 2;
		RigidBodys[idx].SetRadius(100);
		RigidBodys[idx].SetCoordinates({ 500, 200.f + 60 * i });
		RigidBodys[idx].SetSpeed({ 50, 0 });

		RigidBodys[idx + 1].SetRadius(25);
		RigidBodys[idx + 1].SetCoordinates({ 751, 200.f + 60 * i });
		RigidBodys[idx + 1].SetSpeed({ -50, 0 });

	}
	

	MainLoop(RigidBodys);
	delete[] RigidBodys;
}

int main()
{
	Test();

	return 0;
}