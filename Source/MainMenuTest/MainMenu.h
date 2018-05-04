#pragma once

#include "Leaderboard.h"
#include "UI.h"

enum Status { MAIN_MENU, GAME, EXIT };


class MainMenu final {

public:

	static MainMenu* Create(sf::Vector2<float> windowSize, sf::Font& font, UI& ui);
	float GetVolume() { return volumeValue; }
	Status GetCurrentStatus() {  };

	void HandleButtons();
	void Draw();

private:

	enum Buttons { LOGIN, REGISTER, NEW_GAME, OPTIONS, LEADERBOARD };
	enum Panels { MENU_PANEL, LOGIN_PANEL, REGISTER_PANEL, OPTIONS_PANEL, LEADERBOARD_PANEL };

	SfmlButton* loginButton;
	SfmlButton* registerButton;
	SfmlButton* newGameButton;
	SfmlButton* optionsButton;
	SfmlButton* leaderboardButton;

	SfmlButton* logInUserButton;
	SfmlButton* registerUserButton;
	SfmlButton* goBackButton;

	//Label* playerNameLabel;
	//Label* playerPasswordLabel;

	Label* volumeLabel;
	ScrollBar* volumeBar;

	Panels activePanel;
	Status currentStatus;
	float volumeValue;
	Leaderboard* lboard;
	sf::Font* font;


	MainMenu() : loginButton(nullptr), registerButton(nullptr), newGameButton(nullptr), optionsButton(nullptr), leaderboardButton(nullptr),
			logInUserButton(nullptr), registerUserButton(nullptr), goBackButton(nullptr), volumeLabel(nullptr), volumeBar(nullptr), lboard(nullptr), font(font)
	{
		activePanel = MENU_PANEL;
		currentStatus = MAIN_MENU;
		lboard = Leaderboard::Create();
	}

	~MainMenu();

	bool IsButtonPressed(Buttons buttonID) const;

	void OnNewGameButtonPressed();
	void OnLeaderboardButtonPressed();

	void OnLogInUserButtonPressed();
	void OnRegisterUserButtonPressed();
	
	void VolumeHandler();

	void ShowLeaderboard();
};