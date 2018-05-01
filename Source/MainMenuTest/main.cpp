#include "MainMenu.h"
#include <iostream>


using namespace std;

namespace MainMenuTest {

	void Test() {

		sf::RenderWindow rw(sf::VideoMode(1200, 800), "Asteroids");
		//WindowResolution::SetResolution(rw);
		
		UI ui(rw);

		MainMenu *mMenu = MainMenu::Create();
		mMenu->LoginButton = dynamic_cast<SfmlButton*>(ui.CreateButton(sf::Vector2<float>(300, 100), PercentXY(50,30), "LoginButton"));
		mMenu->RegisterButton = dynamic_cast<SfmlButton*>(ui.CreateButton(sf::Vector2<float>(300, 100), PercentXY(50, 35), "RegisterButton"));
		mMenu->NewGameButton = dynamic_cast<SfmlButton*>(ui.CreateButton(sf::Vector2<float>(300, 100), PercentXY(50, 40), "NewGameButton"));
		mMenu->OptionsButton = dynamic_cast<SfmlButton*>(ui.CreateButton(sf::Vector2<float>(300, 100), PercentXY(50, 45), "OptionsButton"));
		mMenu->LeaderboardButton = dynamic_cast<SfmlButton*>(ui.CreateButton(sf::Vector2<float>(300, 100), PercentXY(50, 50), "LeaderboardButton"));


		while (rw.isOpen()) {

			if (mMenu->IsButtonPressed(MainMenu::LOGIN)) {
				cout << "Login button pressed" << endl;
				mMenu->OnLoginButtonPressed();
			}

			if (mMenu->IsButtonPressed(MainMenu::REGISTER)) {
				cout << "Register button pressed" << endl;
				mMenu->OnRegisterButtonPressed();
			}

			if (mMenu->IsButtonPressed(MainMenu::NEW_GAME)) {
				cout << "NewGame button pressed" << endl;
				mMenu->OnNewGameButtonPressed();
			}

			if (mMenu->IsButtonPressed(MainMenu::OPTIONS)) {
				cout << "Options button pressed" << endl;
				mMenu->OnOptionsButtonPressed();
			}

			if (mMenu->IsButtonPressed(MainMenu::LEADERBOARD)) {
				cout << "Leaderboard button pressed" << endl;
				mMenu->OnLeaderboardButtonPressed();
			}

			mMenu->Draw();

		}

	}

}

int main() {

	MainMenuTest::Test();

	return 0;

}