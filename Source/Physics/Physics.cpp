#include "Physics.h"
#include "CollisionEvent.h"

RigidBody::RigidBody() {}

RigidBody::RigidBody(sf::Vector2f c, sf::Vector2f s, float r, float m)
{
  _coords = c;
  _speed  = s;
  _radius = r;
  _mass   = m;
}


void RigidBody::Update(float t)
{
  _coords.x += _speed.x * t;
  _coords.y += _speed.y * t;

  if(_coords.x > W)
  {
    _coords.x = 0;
  }
  if(_coords.x < 0)
  {
    _coords.x = W;
  }
  if(_coords.y > H)
  {
    _coords.y = 0;
  }
  if(_coords.y < 0)
  {
    _coords.y = H;
  }
}


constexpr float tolerance = 1.04f;

void ResolveCollision(const Event& event)
{
	const CollisionEvent collision = static_cast<const CollisionEvent&>(event);
	RigidBody* go1 = collision.obj1;
	RigidBody* go2 = collision.obj2;
  float dx = (go1->_coords.x + go1->_radius - go2->_coords.x - go2->_radius);
  float dy = (go1->_coords.y + go1->_radius - go2->_coords.y - go2->_radius);

  float d1x = go1->_coords.x + go1->_radius;
  float d1y = go1->_coords.y + go1->_radius;

  float d2x = go2->_coords.x + go2->_radius;
  float d2y = go2->_coords.y + go2->_radius;

  float dist = sqrt(dx * dx + dy * dy);

  float overlap = tolerance * (dist - go1->_radius - go2->_radius);

  go1->_coords.x = go1->_coords.x - (overlap * (go1->_coords.x - go2->_coords.x) / dist);
  go1->_coords.y = go1->_coords.y - (overlap * (go1->_coords.y - go2->_coords.y) / dist);

  go2->_coords.x = go2->_coords.x + (overlap * (go1->_coords.x - go2->_coords.x) / dist);
  go2->_coords.y = go2->_coords.y + (overlap * (go1->_coords.y - go2->_coords.y) / dist);

  //normal
  float nx = (d1x - d2x) / dist;
  float ny = (d1y - d2y) / dist;
  //Tanget
  float tx     = -ny;
  float ty     = nx;
  float dpTan1 = go1->_speed.x * tx + go1->_speed.y * ty;
  float dpTan2 = go2->_speed.x * tx + go2->_speed.x * ty;

  float dpNorm1 = go1->_speed.x * nx + go1->_speed.y * ny;
  float dpNorm2 = go2->_speed.x * nx + go2->_speed.x * ny;

  float m1 =
    (dpNorm1 * (go1->_mass - go2->_mass) + 2.0f * go2->_mass * dpNorm2) / (go1->_mass + go2->_mass);
  float m2 =
    (dpNorm2 * (go2->_mass - go1->_mass) + 2.0f * go1->_mass * dpNorm1) / (go1->_mass + go2->_mass);

  // Update ball velocities
  go1->_speed.x = tx * dpTan1 + nx * m1;
  go1->_speed.y = ty * dpTan1 + ny * m1;
  go2->_speed.x = tx * dpTan2 + nx * m2;
  go2->_speed.y = ty * dpTan2 + ny * m2;

}

bool Collided(RigidBody go1, RigidBody go2)
{
  float dx       = (go1._coords.x + go1._radius - go2._coords.x - go2._radius);
  float dy       = (go1._coords.y + go1._radius - go2._coords.y - go2._radius);
  float distance = dx * dx + dy * dy;
  return (distance < (go1._radius + go2._radius) * (go1._radius + go2._radius));
}

void RandomFill(RigidBody * RigidBodysFunc, int length)
{
  std::srand(std::time(nullptr));

  for(int i = 0; i < length; ++i)
  {
    RigidBodysFunc[i]._radius = 10 + std::rand() / ((RAND_MAX + 1u) / 100);
    RigidBodysFunc[i]._coords = {static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / W)),
                                      static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / H))};
    RigidBodysFunc[i]._speed = {static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 200)),
                                static_cast<float>(0 + std::rand() / ((RAND_MAX + 1u) / 15))};
    RigidBodysFunc[i]._mass = 10 + std::rand() / ((RAND_MAX + 1u) / 20);
  }
}
