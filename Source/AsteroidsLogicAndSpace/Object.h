#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
#include "Drawable.h"
class Object :
	public PoolElement, public Drawable
{
public:
	Object() :_window(nullptr), _liveTime(200.0), _allLiveTime(200.0) {}

	virtual void Draw() {}

	virtual void Update(sf::Time time) {}

	virtual ~Object() 	{}

	float _liveTime;
	float _allLiveTime;

	sf::Vector2f _position;
protected:
	void DrawInWindow(const sf::Drawable & obj);
	sf::Vector2u GetSizeWindow() const;
	void SetWindowOneTime(sf::RenderWindow & window);
private:
	sf::RenderWindow *_window;
};