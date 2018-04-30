#include "MainMenu.h"



MainMenu* MainMenu::Create() {

	return new MainMenu();
}


bool MainMenu::IsButtonPressed(SfmlButton* buttonName) const{

	int x0 = buttonName->GetPosition().x;
	int y0 = buttonName->GetPosition().y;

	int x1 = x0 + buttonName->GetSize().x;
	int y1 = y0 + buttonName->GetSize().y;

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