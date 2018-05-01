#pragma once

#include "UI.h"
#include "SfmlButton.h"



class MainMenu final {

public:

	enum Buttons { LOGIN, REGISTER, NEW_GAME, OPTIONS, LEADERBOARD };


	SfmlButton * LoginButton;
	SfmlButton* RegisterButton;
	SfmlButton* NewGameButton;
	SfmlButton* OptionsButton;
	SfmlButton* LeaderboardButton;


	static MainMenu* Create();

	bool IsButtonPressed(Buttons buttonID) const;
	void OnLoginButtonPressed();
	void OnRegisterButtonPressed();
	void OnNewGameButtonPressed();
	void OnOptionsButtonPressed();
	void OnLeaderboardButtonPressed();

	void Draw();

private:

	//background image???

	MainMenu(): LoginButton(nullptr), RegisterButton(nullptr), NewGameButton(nullptr), OptionsButton(nullptr), LeaderboardButton(nullptr) {}
	~MainMenu();
};