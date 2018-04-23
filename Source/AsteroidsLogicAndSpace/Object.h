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

	Object() :_sizeSpace() {}

	void Draw(sf::RenderWindow & window) override {}
	virtual void Update(float time) {}

	virtual ~Object() 	{}

protected:

	void Add() override;
	void Remove();
	int GetZOrder() const  override;
	sf::Vector2u _sizeSpace;
    sf::Vector2u GetSizeWindow() const;

};