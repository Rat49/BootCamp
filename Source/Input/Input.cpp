#include "Input.h"
#include <cassert>
#include <iostream>

InputManager::InputManager(const std::map<int, int>& buttonsKeyFromConfig)
{
	for (int action = static_cast<int> (GameActions::Up), lastAction = static_cast<int> (GameActions::Space); action <= lastAction; ++action)
	{
		buttonsState.insert(std::pair<int, int>(action, static_cast<int>(ButtonsState::Released)));
	}
	buttonsKey.insert(buttonsKeyFromConfig.begin(), buttonsKeyFromConfig.end());
}


InputManager::~InputManager()
{

}

std::map<int, int> InputManager::GetState() const {
	return buttonsState;
}

int InputManager::ChangeStateWhenPressed(int currentState) {
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return static_cast<int>(ButtonsState::Pressed);
		break;
	case ButtonsState::Pressed:
		return static_cast<int>(ButtonsState::Pressed);
		break;
	case ButtonsState::JustReleased:
		return static_cast<int>(ButtonsState::JustPressed);
		break;
	case ButtonsState::Released:
		return static_cast<int>(ButtonsState::JustPressed);
		break;
	default:
		return static_cast<int>(ButtonsState::Pressed);
		break;
	}
	
};

int InputManager::ChangeStateWhenRelease(int currentState) {
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return static_cast<int>(ButtonsState::JustReleased);
		break;
	case ButtonsState::Pressed:
		return static_cast<int>(ButtonsState::JustReleased);
		break;
	case ButtonsState::JustReleased:
		return static_cast<int>(ButtonsState::Released);
		break;
	case ButtonsState::Released:
		return static_cast<int>(ButtonsState::Released);
		break;
	default:
		return static_cast<int>(ButtonsState::Released);
		break;
	}

};

void InputManager::Update() {
	for (auto &key : buttonsKey) 
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key.second))) {
			std::map<int, int>::iterator endOfButtonsState = std::end(buttonsState);
			std::map<int,int>::iterator pair = buttonsState.find(key.first);
			
			assert(pair != endOfButtonsState);
			
			pair->second = ChangeStateWhenPressed(pair->second);
		}
		else {
			std::map<int, int>::iterator endOfButtonsState = std::end(buttonsState);
			std::map<int, int>::iterator pair = buttonsState.find(key.first);

			assert(pair != endOfButtonsState);

			pair->second = ChangeStateWhenRelease(pair->second);
		}
	}

}
