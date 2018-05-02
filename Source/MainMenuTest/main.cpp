#include "MainMenu.h"
#include <iostream>


using namespace std;

namespace MainMenuTest {

	void Test() {

		sf::RenderWindow rw(sf::VideoMode(1200, 800), "Asteroids");
		//WindowResolution::SetResolution(rw);
		
		UI ui(rw);

		MainMenu *mMenu = MainMenu::Create(sf::Vector2f(1200, 800), ui);


		while (rw.isOpen()) {

			mMenu->HandleButtons();
			mMenu->Draw();
			rw.display();

		}

	}

}

int main() {

	MainMenuTest::Test();

	return 0;

}