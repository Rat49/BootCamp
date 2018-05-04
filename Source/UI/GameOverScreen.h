#pragma once
#include "Drawable.h"
#include "DrawableManager.h"
#include "AnimationPlayer.h"
#include "EventSystem.h"
#include "WindowResolution.h"

class GameOverScreen : public Drawable
{
private:
	AnimationPlayer* _gameOverFlickering;
	ImageSequenceResource* _gameOverImseq;
	sf::Sprite _gameOverSprite;
	Token_t _gameOver;
	Token_t _gameReset;
public:
	GameOverScreen(ResourceManager* rm);
	~GameOverScreen();
	void Update(const sf::Time& fixedTime);
	void AddToDrawableManager();
	void RemoveFromDrawableManager();
	void Draw(sf::RenderWindow& window);
	int GetZOrder() const;
};