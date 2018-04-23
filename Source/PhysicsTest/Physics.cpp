#include "Physics.h"
#include "EventSystem.h"
#include "CollisionEvent.h"


constexpr size_t numOfObjects = 10;
void             MainLoop(RigidBody * RigidBodysFunc)
{
  sf::Clock clock;
  sf::Time  deltaTime;

  sf::RenderWindow app(sf::VideoMode(W, H), "Asteroids!");

  sf::CircleShape circles[numOfObjects];
  sf::CircleShape circlesCenters[numOfObjects];

  CollisionEvent collisionEvent;
  Dispatcher &   dispatcher = Dispatcher::getInstance();
  dispatcher.Connect(collisionEventID, ResolveCollision);

  for(int i = 0; i < numOfObjects; ++i)
  {
    circles[i].setRadius(RigidBodysFunc[i]._radius);
    circles[i].setPosition(RigidBodysFunc[i]._coords.x, RigidBodysFunc[i]._coords.y);
    circlesCenters[i].setPosition(RigidBodysFunc[i]._coords.x + RigidBodysFunc[i]._radius,
                                  RigidBodysFunc[i]._coords.y + RigidBodysFunc[i]._radius);
    circlesCenters[i].setRadius(1.f);
    circlesCenters[i].setFillColor(sf::Color::Green);
  }
  constexpr float physicsStepTargetFrameTime = 1e3 / 60.f;
  float           accumulatedFrameTime       = 0.f;
  while(app.isOpen())
  {
    const float delta = clock.restart().asMicroseconds() / 1e3;
    accumulatedFrameTime += delta;
    sf::Event event;
    while(app.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        app.close();
      }
    }
    for(int i = 0; i < numOfObjects; ++i)
      circles[i].setFillColor(sf::Color::White);
    while(accumulatedFrameTime >= physicsStepTargetFrameTime)
    {
      accumulatedFrameTime -= physicsStepTargetFrameTime;
      for(int i = 0; i < numOfObjects - 1; ++i)
      {
        for(int j = i + 1; j < numOfObjects; ++j)
        {
            if(Collided(RigidBodysFunc[i], RigidBodysFunc[j]))
            {
              circles[i].setFillColor(sf::Color::Red);
              circles[j].setFillColor(sf::Color::Red);
              collisionEvent.setObjs(&RigidBodysFunc[i], &RigidBodysFunc[j]);
              dispatcher.Send(collisionEvent, collisionEventID);
              //ResolveCollision(RigidBodysFunc[i], RigidBodysFunc[j]);
          }
        }
      }

      for(int i = 0; i < numOfObjects; ++i)
      {
        RigidBodysFunc[i].Update(physicsStepTargetFrameTime / 1e3);
        circles[i].setPosition(RigidBodysFunc[i]._coords.x, RigidBodysFunc[i]._coords.y);
        circlesCenters[i].setPosition(RigidBodysFunc[i]._coords.x + RigidBodysFunc[i]._radius,
                                      RigidBodysFunc[i]._coords.y + RigidBodysFunc[i]._radius);
      }
    }
    app.clear();
    for(int i = 0; i < numOfObjects; ++i)
    {
      app.draw(circles[i]);
      app.draw(circlesCenters[i]);
    }
    app.display();
  }
}

void Test()
{
  RigidBody * RigidBodys = new RigidBody[numOfObjects];
  /*RandomFill(RigidBodys, numOfObjects);*/

  for(int i = 0; i < numOfObjects / 2; i++)
  {
    const int idx = i * 2;
    RigidBodys[idx]._radius =10;
    RigidBodys[idx]._coords = {500, 200.f + 60 * i};
    RigidBodys[idx]._speed = {60, 15};
    RigidBodys[idx]._mass = 0.005f;

    RigidBodys[idx + 1]._radius = 25;
    RigidBodys[idx + 1]._coords = {750, 250.f + 60 * i};
    RigidBodys[idx + 1]._speed = {-100, 40};
    RigidBodys[idx + 1]._mass = 0.01f;
  }


  MainLoop(RigidBodys);
  delete[] RigidBodys;
}

int main()
{
  Test();

  return 0;
}
