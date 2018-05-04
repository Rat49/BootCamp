#include "MainMenu.h"



MainMenu* MainMenu::Create(sf::Vector2<float> windowSize, sf::Font& font, UI& ui) {

	MainMenu *mm = new MainMenu();

	float width = windowSize.x;
	float hight = windowSize.y;

	int buttonWidth = width / 3;
	int buttonHight = hight / 10;

	sf::Vector2f buttonSize = {(float)buttonWidth, (float)buttonHight};

	mm->loginButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 30), "Login"));
	mm->registerButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 35), "Register"));
	mm->newGameButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 40), "NewGame"));
	mm->optionsButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 45), "Options"));
	mm->leaderboardButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 50), "Leaderboard"));

	mm->userNameLabel = dynamic_cast<Label*>(ui.CreateLabel("Enter your username", font, PercentXY(50, 40), "UserNameLabel"));
	mm->logInUserButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 60), "LogIn"));
	mm->registerUserButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 60), "Register"));
	mm->goBackButton = dynamic_cast<SfmlButton*>(ui.CreateButton(font, buttonSize, PercentXY(50, 80), "GoBack"));

	mm->volumeLabel = dynamic_cast<Label*>(ui.CreateLabel("Set the volume of sounds", font, PercentXY(50, 40), "VolumeLabel"));
	mm->volumeBar = dynamic_cast<ScrollBar*>(ui.CreateScrollBar(buttonWidth, PercentXY(50, 60), "VolumeBar"));

	for (unsigned i = 0; i < 10; ++i) {
		for (unsigned j = 0; j < 3; ++j) {
			mm->topScores[i][j] = dynamic_cast<Label*>(ui.CreateLabel("", font, PercentXY(j*33, i*10), "ScoreLabel"));
		}
	}

	return mm;
}

void MainMenu::HandleButtons() {

	if (sf::Mouse::isButtonPressed) {
		int mouseX = sf::Mouse::getPosition().x;
		int mouseY = sf::Mouse::getPosition().y;

		sf::Vector2i mousePosition = { mouseX, mouseY };

		switch (activePanel) {

		case MENU_PANEL:
			if (loginButton->IsClicked(mousePosition)){
				//cout << "Login button pressed" << endl;
				activePanel = LOGIN_PANEL;
			}
			if (registerButton->IsClicked(mousePosition)) {
				//cout << "Register button pressed" << endl;
				activePanel = REGISTER_PANEL;
			}
			if (newGameButton->IsClicked(mousePosition)) {
				//cout << "NewGame button pressed" << endl;
				OnNewGameButtonPressed();
			}
			if (optionsButton->IsClicked(mousePosition)) {
				//cout << "Options button pressed" << endl;
				activePanel = OPTIONS_PANEL;
			}
			if (leaderboardButton->IsClicked(mousePosition)) {
				//cout << "Leaderboard button pressed" << endl;
				OnLeaderboardButtonPressed();
			}
			break;

		case LOGIN_PANEL:
			EnterUserNameHandler();
			if (logInUserButton->IsClicked(mousePosition)) {
				OnLogInUserButtonPressed();
			}
			if (goBackButton->IsClicked(mousePosition)) {
				activePanel = MENU_PANEL;
			}
			break;

		case REGISTER_PANEL:
			if (registerUserButton->IsClicked(mousePosition)) {
				OnRegisterUserButtonPressed();
			}
			if (goBackButton->IsClicked(mousePosition)) {
				activePanel = MENU_PANEL;
			}
			break;

		case OPTIONS_PANEL:
			VolumeHandler();

			if (goBackButton->IsClicked(mousePosition)) {
				activePanel = MENU_PANEL;
			}
			break;

		case LEADERBOARD_PANEL:
			ShowLeaderboard();
			if (goBackButton->IsClicked(mousePosition)) {
				activePanel = MENU_PANEL;
			}
		}
	}
}

void MainMenu::Draw() {

	//first draw background if exist

	switch (activePanel) {
	case MENU_PANEL:
		loginButton->Draw();
		registerButton->Draw();
		newGameButton->Draw();
		optionsButton->Draw();
		leaderboardButton->Draw();
		break;

	case LOGIN_PANEL:
		userNameLabel->Draw();
		logInUserButton->Draw();
		goBackButton->Draw();
		break;

	case REGISTER_PANEL:
		userNameLabel->Draw();
		registerUserButton->Draw();
		goBackButton->Draw();
		break;

	case OPTIONS_PANEL:
		volumeLabel->Draw();
		volumeBar->Draw();
		goBackButton->Draw();
		break;

	case LEADERBOARD_PANEL:
		DrawLeaderboard();
		goBackButton->Draw();
	}
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
		default:
			button = loginButton;
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

void MainMenu::OnNewGameButtonPressed() {
	currentStatus = GAME;
}

void MainMenu::OnLeaderboardButtonPressed() {

	activePanel = LEADERBOARD_PANEL;

	lboard->UpdateLocalLeaderboard();

}

void MainMenu::OnLogInUserButtonPressed() {

	std::string username = userNameLabel->GetContent();

	if (!username.empty() || username == "Enter your username")
		lboard->Login(username);
}

void MainMenu::OnRegisterUserButtonPressed() {

	std::string username = userNameLabel->GetContent();

	if (!username.empty() || username == "Enter your username")
		lboard->Login(username, true);
}

void MainMenu::VolumeHandler() {

	volumeValue = volumeBar->GetSliderPosition();
}

void MainMenu::EnterUserNameHandler() {
	std::string username;

	std::cin >> username;

	userNameLabel->SetString(username);
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
	if (logInUserButton != nullptr) {
		delete logInUserButton;
	}
	if (registerUserButton != nullptr) {
		delete registerUserButton;
	}
	if (goBackButton != nullptr) {
		delete goBackButton;
	}
	if (userNameLabel != nullptr) {
		delete userNameLabel;
	}
	if (volumeLabel != nullptr) {
		delete volumeLabel;
	}
	if (volumeBar != nullptr) {
		delete volumeBar;
	}
	if (lboard != nullptr) {
		delete lboard;
	}
}

void MainMenu::ShowLeaderboard() {
	lboard->UpdateLocalLeaderboard();

	int i = 0;
	for (auto l : lboard->leaderboard)
	{
		std::ostringstream position, display, value;

		position << l.Position;
		display << l.DisplayName;
		value << l.StatValue;

		topScores[i][1]->SetString(position.str());
		topScores[i][1]->SetString(display.str());
		topScores[i][2]->SetString(value.str());

		++i;
	}

}

void MainMenu::DrawLeaderboard() {

	for (unsigned i = 0; i < topScores.size(); ++i) {
		for (unsigned j = 0; j < topScores.size(); ++j) {
			topScores[i][j]->Draw();
		}
	}
}