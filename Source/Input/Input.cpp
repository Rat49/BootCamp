#include "Input.h"
#include <cassert>
#include <iostream>

InputManager::InputManager(const std::map<Action_t, ButtonKey_t>& _buttonsKeyFromConfig)
{
	for (auto _actionIt = std::cbegin(_buttonsKeyFromConfig); _actionIt != std::cend(_buttonsKeyFromConfig); ++_actionIt)
	{
		_buttonsState[_actionIt->first] = static_cast<State_t>(ButtonsState::Released);
		
		_buttonsKey[_actionIt->first] = _actionIt->second;
		
	}
}

bool InputManager::GetState(const Action_t _searchAction, ButtonsState & _result) const {
	bool _success = false;
	for (auto _actionIt = std::cbegin(_buttonsState); _actionIt != std::cend(_buttonsState); ++_actionIt)
	{
		if (_actionIt->first == _searchAction) {
			_result = static_cast<ButtonsState>(_actionIt->second);
			_success = true;
		}
	}
	return _success;
}

State_t InputManager::ChangeStateWhenPressed(State_t currentState) {
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return static_cast<State_t>(ButtonsState::Pressed);
	case ButtonsState::Pressed:
		return static_cast<State_t>(ButtonsState::Pressed);
	case ButtonsState::JustReleased:
		return static_cast<State_t>(ButtonsState::JustPressed);
	case ButtonsState::Released:
		return static_cast<State_t>(ButtonsState::JustPressed);
	default:
		return static_cast<State_t>(ButtonsState::Pressed);
	}
	
};

State_t InputManager::ChangeStateWhenRelease(State_t currentState) {
	switch (static_cast<ButtonsState>(currentState))
	{
	case ButtonsState::JustPressed:
		return static_cast<State_t>(ButtonsState::JustReleased);
	case ButtonsState::Pressed:
		return static_cast<State_t>(ButtonsState::JustReleased);
	case ButtonsState::JustReleased:
		return static_cast<State_t>(ButtonsState::Released);
	case ButtonsState::Released:
		return static_cast<State_t>(ButtonsState::Released);
	default:
		return static_cast<State_t>(ButtonsState::Released);
	}

};

void InputManager::Update() {
	for (auto &_action : _buttonsKey)
	{
		std::map<Action_t, State_t>::iterator _buttonState = _buttonsState.find(_action.first);
		assert(_buttonState != std::cend(_buttonsState));
		bool _pressed = false;
		for (auto &_key : _action.second) {
			if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(_key)))
			{
				_pressed = true;
			}
		}

		if (_pressed)
			_buttonState->second = ChangeStateWhenPressed(_buttonState->second);
		else
			_buttonState->second = ChangeStateWhenRelease(_buttonState->second);
	}

}
