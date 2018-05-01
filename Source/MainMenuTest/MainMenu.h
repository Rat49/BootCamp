#pragma once

#include "Leaderboard.h"
#include "UI.h"
#include "SfmlButton.h"



class MainMenu final {

public:

	enum Buttons { LOGIN, REGISTER, NEW_GAME, OPTIONS, LEADERBOARD };
	enum Panels { MENU_PANEL, LOGIN_PANEL, OPTIONS_PANEL, LEADERBOARD_PANEL };

	SfmlButton* loginButton;
	SfmlButton* registerButton;
	SfmlButton* newGameButton;
	SfmlButton* optionsButton;
	SfmlButton* leaderboardButton;


	static MainMenu* Create();

	bool IsButtonPressed(Buttons buttonID) const;
	void OnLoginButtonPressed();
	void OnRegisterButtonPressed();
	void OnNewGameButtonPressed();
	void OnOptionsButtonPressed();
	void OnLeaderboardButtonPressed();

	float GetSoundVolume() { return soundVolume; }

	void Draw();

private:

	Panels activePanel;
	float soundVolume;
	Leaderboard* lboard;


	MainMenu() : loginButton(nullptr), registerButton(nullptr), newGameButton(nullptr), optionsButton(nullptr), leaderboardButton(nullptr), lboard(nullptr) {
		activePanel = MENU_PANEL;
		lboard = Leaderboard::Create();
	}

	~MainMenu();

	void ShowLeaderboard();
};