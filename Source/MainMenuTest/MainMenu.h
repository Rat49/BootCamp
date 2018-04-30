#pragma once

#include "UI.h"
#include "SfmlButton.h"



class MainMenu final {

public:
	static MainMenu* Create();

	bool IsButtonPressed(SfmlButton* buttonName) const;

	void OnLoginButtonPressed();
	void OnRegisterButtonPressed();

private:

	SfmlButton* LoginButton;
	SfmlButton* RegisterButton;

	MainMenu() {}
};