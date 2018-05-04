#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(ResourceManager *rm)
{
	_gameOverImseq = rm->GetResource<ImageSequenceResource>("gameOver");
	_gameOverFlickering = new AnimationPlayer(&_gameOverSprite, _gameOverImseq, true);
	_gameOverFlickering->Start();
	_zOrder = 1;

	_gameOver = Dispatcher::getInstance().Connect(gameOverEventID, [&](const Event& event)
	{
		AddToDrawableManager();
	});

	_gameReset = Dispatcher::getInstance().Connect(resetGameEventID, [&](const Event& event)
	{
		RemoveFromDrawableManager();
	});

}

GameOverScreen::~GameOverScreen()
{
	Dispatcher::getInstance().Disconnect(gameOverEventID, _gameOver);
	Dispatcher::getInstance().Disconnect(resetGameEventID, _gameReset);
}

void GameOverScreen::Update(const sf::Time& fixedTime) 
{
	_gameOverFlickering->Update(fixedTime);
	_gameOverSprite.setPosition({ (WindowResolution::_W - _gameOverSprite.getTextureRect().width) / 2.f, 100 });
}

void GameOverScreen::AddToDrawableManager() 
{
	DrawableManager::getInstance().AddDrawableObject(this);
}
void GameOverScreen::RemoveFromDrawableManager()
{
	DrawableManager::getInstance().RemoveDrawableObject(this);
}

void GameOverScreen::Draw(sf::RenderWindow& window)
{
	window.draw(_gameOverSprite);
}
	
int GameOverScreen::GetZOrder() const
{
	return _zOrder;
}
