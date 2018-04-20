#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
#include "Drawable.h"
#include "DrawableManager.h"
class Object :
	public PoolElement, public Drawable
{
public:
	Object() :_sizeSpace(), _liveTime(200.0), _allLiveTime(200.0) 
	{
		Add();
	}

	void Draw(sf::RenderWindow & window) override {};

	virtual void Update(sf::Time time) {};

	virtual ~Object() 	{}

	float _liveTime;
	float _allLiveTime;

	sf::Vector2f _position;
protected:
	void Add() override;
	int GetZOrder() const  override;
	sf::Vector2u _sizeSpace;
//protected:
//	void DrawInWindow(const sf::Drawable & obj);
    sf::Vector2u GetSizeWindow() const;
//	void SetWindowOneTime(sf::RenderWindow & window);
//private:
//	sf::RenderWindow *_window;
};