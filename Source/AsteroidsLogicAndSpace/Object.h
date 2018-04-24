#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
#include "Drawable.h"
#include "DrawableManager.h"
#include "EventSystem.h"
class Object :
	public Drawable, public PoolElement
{
public:

	//TODO: move to ObjectManager
	static std::vector<Object*> _allObjects;

	Object() :_sizeSpace() {}

	void Draw(sf::RenderWindow & window) override {}
	virtual void Update(float time) {}
	void Add() override;
	virtual void Remove();

	virtual ~Object() 	{}

protected:

	int GetZOrder() const  override;
	sf::Vector2u _sizeSpace;
    sf::Vector2u GetSizeWindow() const;

};