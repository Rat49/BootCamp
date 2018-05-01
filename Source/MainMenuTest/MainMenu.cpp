#include "MainMenu.h"



MainMenu* MainMenu::Create() {

	return new MainMenu();
}


bool MainMenu::IsButtonPressed(Buttons buttonID) const{

	SfmlButton* button;

	switch (buttonID) {
		case LOGIN:
			button = loginButton;
			break;
		case REGISTER:
			button = registerButton;
			break;
		case NEW_GAME:
			button = newGameButton;
			break;
		case OPTIONS:
			button = optionsButton;
			break;
		case LEADERBOARD:
			button = leaderboardButton;
	}

	int x0 = button->GetPosition().x;
	int y0 = button->GetPosition().y;

	int x1 = x0 + button->GetSize().x;
	int y1 = y0 + button->GetSize().y;

	if (sf::Mouse::isButtonPressed) {
		
		int mouseX = sf::Mouse::getPosition().x;
		int mouseY = sf::Mouse::getPosition().y;

		if ( (mouseX >= x0) && (mouseX <= x1) && (mouseY >= y0) && (mouseY <= y1) ) {
			return true;
		}
	}

	return false;
}


void MainMenu::OnLoginButtonPressed() {

	activePanel = LOGIN_PANEL;

	std::string nickname;

	//enter nickname

	lboard->Login(nickname);

}

void MainMenu::OnRegisterButtonPressed() {

	activePanel = LOGIN_PANEL;

	std::string nickname;

	//enter nickname

	lboard->Login(nickname, true);
}

void MainMenu::OnNewGameButtonPressed() {

}

void MainMenu::OnOptionsButtonPressed() {

	activePanel = OPTIONS_PANEL;

	float volume;


	soundVolume = volume;
}

void MainMenu::OnLeaderboardButtonPressed() {

	activePanel = LEADERBOARD_PANEL;

	lboard->UpdateLocalLeaderboard();
	
}

void MainMenu::Draw() {

	//first draw background if exist

	if (activePanel == MENU_PANEL) {

		loginButton->Draw();
		registerButton->Draw();
		newGameButton->Draw();
		optionsButton->Draw();
		leaderboardButton->Draw();
	}

}

MainMenu::~MainMenu() {

	if (loginButton != nullptr) {
		delete loginButton;
	}

	if (registerButton != nullptr) {
		delete registerButton;
	}

	if (newGameButton != nullptr) {
		delete newGameButton;
	}

	if (optionsButton != nullptr) {
		delete optionsButton;
	}

	if (leaderboardButton != nullptr) {
		delete leaderboardButton;
	}

	if (lboard != nullptr) {
		delete lboard;
	}
}

void MainMenu::ShowLeaderboard() {
	lboard->UpdateLocalLeaderboard();

	//std::list<PlayFab::ClientModels::PlayerLeaderboardEntry> leaderboard;

	//lboard->leaderboard;  //????


}