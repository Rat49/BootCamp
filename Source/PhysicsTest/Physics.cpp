#include "Physics.h"
#include "CollisionEventForTest.h"
#include "EventSystem.h"
//#include "CollisionEventPhysicstest.h"


constexpr size_t numOfObjects = 20;
void             MainLoop(RigidBody * RigidBodysFunc)
{
  sf::Clock clock;
  sf::Time  deltaTime;

  sf::RenderWindow app(sf::VideoMode(800,800), "Asteroids!");
  WindowResolution::SetResolution(app);

  sf::CircleShape circles[numOfObjects];
  sf::CircleShape circlesCenters[numOfObjects];

  CollisionEventForTest collisionEvent;
  Dispatcher &   dispatcher = Dispatcher::getInstance();

  for(int i = 0; i < numOfObjects; ++i)
  {
    circles[i].setRadius(RigidBodysFunc[i].GetRadius());
    circles[i].setPosition(RigidBodysFunc[i].GetX(), RigidBodysFunc[i].GetY());
    circlesCenters[i].setPosition(RigidBodysFunc[i].GetX() + RigidBodysFunc[i].GetRadius(),
                                  RigidBodysFunc[i].GetY() + RigidBodysFunc[i].GetRadius());
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
			  collisionEvent._rigidBody1 = &RigidBodysFunc[i];
			  collisionEvent._rigidBody2 = &RigidBodysFunc[j];
              dispatcher.Send(collisionEvent, firstEventID); //EventType and ID doesn't match in test, but should in 
              ResolveCollision(RigidBodysFunc[i], RigidBodysFunc[j]);
          }
        }
      }

      for(int i = 0; i < numOfObjects; ++i)
      {
        RigidBodysFunc[i].Update(physicsStepTargetFrameTime / 1e3);
        circles[i].setPosition(RigidBodysFunc[i].GetX(), RigidBodysFunc[i].GetY());
        circlesCenters[i].setPosition(RigidBodysFunc[i].GetX() + RigidBodysFunc[i].GetRadius(),
                                      RigidBodysFunc[i].GetY() + RigidBodysFunc[i].GetRadius());
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
    RigidBodys[idx].SetRadius(10);
    RigidBodys[idx].SetCoordinates({500, 200.f + 60 * i});
    RigidBodys[idx].SetSpeed({60, 15});
    RigidBodys[idx].SetMass(0.005f);

    RigidBodys[idx + 1].SetRadius(25);
    RigidBodys[idx + 1].SetCoordinates({750, 250.f + 60 * i});
    RigidBodys[idx + 1].SetSpeed({-100, 40});
    RigidBodys[idx + 1].SetMass(0.01f);
  }


  MainLoop(RigidBodys);
  delete[] RigidBodys;
}

int main()
{
  Test();

  return 0;
}
