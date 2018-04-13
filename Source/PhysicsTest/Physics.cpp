#include "Physics.h"
#include "EventSystem.h"



void Draw(RigidBody *RigidBodysFunc, int length) {
	sf::Clock clock;
	sf::Time deltaTime;

	sf::RenderWindow app(sf::VideoMode(W, H), "Asteroids!");

	sf::CircleShape* circles = new sf::CircleShape[length];

	for (int i = 0; i < length; ++i) {
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

		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (i != j) {
					if (Collided(RigidBodysFunc[i], RigidBodysFunc[j])) {
						ResolveCollision(RigidBodysFunc[i], RigidBodysFunc[j]);
						circles[i].setFillColor(sf::Color::Red);
						circles[j].setFillColor(sf::Color::Red);
					}
					else {
						circles[i].setFillColor(sf::Color::White);
						circles[j].setFillColor(sf::Color::White);
					}
				}
			}
		}

		for (int i = 0; i < length; ++i) {
			RigidBodysFunc[i].Update(deltaSeconds);
			circles[i].setPosition(RigidBodysFunc[i].GetX(), RigidBodysFunc[i].GetY());
		}

		app.clear();
		for (int i = 0; i < length; ++i) {
			app.draw(circles[i]);
		}
		app.display();
	}

	delete[] circles;
}

void Test(int numOfObjects) {
	RigidBody* RigidBodys = new RigidBody[numOfObjects];
	RandomFill(RigidBodys, numOfObjects);

	Dispatcher& dispatcher = Dispatcher::getInstance();

	/*
	RigidBodys[0].SetRadius(25);
	RigidBodys[0].SetCoordinates({ 500, 500 });
	RigidBodys[0].SetSpeed({ 10, 0 });

	RigidBodys[1].SetRadius(25);
	RigidBodys[1].SetCoordinates({ 751, 501 });
	RigidBodys[1].SetSpeed({ -10, 0 });
	*/

	Draw(RigidBodys, numOfObjects);
	delete[] RigidBodys;
}

int main()
{
	Test(20);

	return 0;
}