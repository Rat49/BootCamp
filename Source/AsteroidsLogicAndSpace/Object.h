#pragma once
#include "SFML/Graphics.hpp"
#include "Pool.h"
class Object :
	public PoolElement
{
public:
	Object() :_window(nullptr), _live(200.0){}

	virtual void Draw() {}

	virtual void Update(sf::Time time) {}

	virtual ~Object() 	{}

	float _live;
protected:
	void DrawInWindow(const sf::Drawable & obj);
	sf::Vector2u GetSizeWindow() const;
	void SetWindowOneTime(sf::RenderWindow & window);
private:
	sf::RenderWindow *_window;
};