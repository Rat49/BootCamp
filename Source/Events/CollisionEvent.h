#pragma once
#include "Event.h"
#include "Physics.h"
#include <vector>
#include "Pool.h"
template<class T>
class CollisionEvent : public Event
{
public:
	CollisionEvent(Pool<T> &poolOwner,std::vector<T*> &owner):_poolOwner(poolOwner), _owner(owner){};
	~CollisionEvent(){};
	T *_obj1, *_obj2;
	std::vector<T*> &_owner;
	Pool<T> &_poolOwner;
};
