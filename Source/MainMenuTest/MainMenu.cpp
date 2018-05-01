#include "MainMenu.h"



MainMenu* MainMenu::Create() {

	return new MainMenu();
}


bool MainMenu::IsButtonPressed(Buttons buttonID) const{

	SfmlButton* button;

	switch (buttonID) {
		case LOGIN:
			button = LoginButton;
			break;
		case REGISTER:
			button = RegisterButton;
			break;
		case NEW_GAME:
			button = NewGameButton;
			break;
		case OPTIONS:
			button = OptionsButton;
			break;
		case LEADERBOARD:
			button = LeaderboardButton;
	}

	int x0 = button->GetPosition().x;
	int y0 = button->GetPosition().y;

	int x1 = x0 + button->GetSize().x;
	int y1 = y0 + button->GetSize().y;

	if (sf::Mouse::isButtonPressed) {
		
		int mouseX = sf::Mouse::getPosition().x;
		int mouseY = sf::Mouse::getPosition().x;

		if ( (mouseX >= x0) && (mouseX <= x1) && (mouseY >= y0) && (mouseY <= y1) ) {
			return true;
		}
	}

	return false;
}


void MainMenu::OnLoginButtonPressed() {

}

void MainMenu::OnRegisterButtonPressed() {

}

void MainMenu::OnNewGameButtonPressed() {

}

void MainMenu::OnOptionsButtonPressed() {

}

void MainMenu::OnLeaderboardButtonPressed() {

}

void MainMenu::Draw() {

	//first draw background if exist

	LoginButton->Draw();
	RegisterButton->Draw();
	NewGameButton->Draw();
	OptionsButton->Draw();
	LeaderboardButton->Draw();

}


MainMenu::~MainMenu() {

	if (LoginButton != nullptr) {
		delete LoginButton;
	}

	if (RegisterButton != nullptr) {
		delete RegisterButton;
	}

	if (NewGameButton != nullptr) {
		delete NewGameButton;
	}

	if (OptionsButton != nullptr) {
		delete OptionsButton;
	}

	if (LeaderboardButton != nullptr) {
		delete LeaderboardButton;
	}
}