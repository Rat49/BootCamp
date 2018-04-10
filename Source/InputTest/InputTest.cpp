#include "Input.h"
#include <cassert>
#include <iostream>
#include <map>

enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot
};

ButtonKey_t _up = { static_cast<int>(sf::Keyboard::Up),static_cast<int>(sf::Keyboard::W) };
ButtonKey_t _down = { static_cast<int>(sf::Keyboard::Down),static_cast<int>(sf::Keyboard::S) };
ButtonKey_t _left = { static_cast<int>(sf::Keyboard::Left),static_cast<int>(sf::Keyboard::A) };
ButtonKey_t _right = { static_cast<int>(sf::Keyboard::Right),static_cast<int>(sf::Keyboard::D) };
ButtonKey_t _exiT = { static_cast<int>(sf::Keyboard::Escape) };
ButtonKey_t _choose = { static_cast<int>(sf::Keyboard::Return) };
ButtonKey_t _shoot = { static_cast<int>(sf::Keyboard::Space) };

std::map<int, ButtonKey_t> init() {

	std::map<int, ButtonKey_t> _customActions = {
		{ static_cast<int>(GameActions::MoveUp),    _up},
		{ static_cast<int>(GameActions::MoveDown),  _down},
		{ static_cast<int>(GameActions::MoveLeft),  _left},
		{ static_cast<int>(GameActions::MoveRight), _right},
		{ static_cast<int>(GameActions::Exit),      _exiT},
		{ static_cast<int>(GameActions::Choose),    _choose},
		{ static_cast<int>(GameActions::Shoot),		_shoot}
	};

	return _customActions;
}

std::string GetNameForState(ButtonsState _bState) {

	switch (_bState)
	{
	case ButtonsState::JustPressed:
		return "JustPressed";
	case ButtonsState::Pressed:
		return "Pressed";
	case ButtonsState::JustReleased:
		return "JustReleased";
	case ButtonsState::Released:
		return "Released";
	default:
		return "Undefined";
		break;
	}
}

int main()
{
	std::map<int, ButtonKey_t> _actions = init();

	if (_actions.empty())
	{
		std::cout << "Failed: Actions from Config is empty!" << std::endl;
		return 1;
	}

	InputManager input(_actions);

	// ~~~~~~~~~~~~ Only for test mode! ~~~~~~~~~~~~~~
	// We don't want to see "released" or "pressed" all the time - so let's print to the console only when state changes
	ButtonsState _previousStateMoveUp = ButtonsState::Released;
	ButtonsState _previousStateMoveDown = ButtonsState::Released;
	ButtonsState _previousStateMoveLeft = ButtonsState::Released;
	ButtonsState _previousStateMoveRight = ButtonsState::Released;
	ButtonsState _previousStateExit = ButtonsState::Released;
	ButtonsState _previousStateChoose = ButtonsState::Released;
	ButtonsState _previousStateShoot = ButtonsState::Released;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	ButtonsState _stateMoveUp;
	ButtonsState _stateMoveDown;
	ButtonsState _stateMoveLeft;
	ButtonsState _stateMoveRight;
	ButtonsState _stateExit;
	ButtonsState _stateChoose;
	ButtonsState _stateShoot;
	
	while (true)
	{
		input.Update();

		if (input.GetState(static_cast<int>(GameActions::MoveUp), _stateMoveUp) && _previousStateMoveUp!= _stateMoveUp)
		{
			std::cout << "MoveUp state - " << GetNameForState(_stateMoveUp) << std::endl;
			_previousStateMoveUp = _stateMoveUp;
		}
		if (input.GetState(static_cast<int>(GameActions::MoveDown), _stateMoveDown) && _previousStateMoveDown != _stateMoveDown)
		{
			std::cout << "MoveDown state - " << GetNameForState(_stateMoveDown) << std::endl;
			_previousStateMoveDown = _stateMoveDown;
		}
		if (input.GetState(static_cast<int>(GameActions::MoveLeft), _stateMoveLeft) && _previousStateMoveLeft != _stateMoveLeft)
		{
			std::cout << "MoveLeft state - " << GetNameForState(_stateMoveLeft) << std::endl;
			_previousStateMoveLeft = _stateMoveLeft;
		}
		if (input.GetState(static_cast<int>(GameActions::MoveRight), _stateMoveRight) && _previousStateMoveRight != _stateMoveRight)
		{
			std::cout << "MoveRight state - " << GetNameForState(_stateMoveRight) << std::endl;
			_previousStateMoveRight = _stateMoveRight;
		}
		if (input.GetState(static_cast<int>(GameActions::Exit), _stateExit) && _previousStateExit != _stateExit)
		{
			std::cout << "Exit state - " << GetNameForState(_stateExit) << std::endl;
			_previousStateExit = _stateExit;
		}
		if (input.GetState(static_cast<int>(GameActions::Choose), _stateChoose) && _previousStateChoose != _stateChoose)
		{
			std::cout << "Choose state - " << GetNameForState(_stateChoose) << std::endl;
			_previousStateChoose = _stateChoose;
		}
		if (input.GetState(static_cast<int>(GameActions::Shoot), _stateShoot) && _previousStateShoot != _stateShoot)
		{
			std::cout << "Shoot state - " << GetNameForState(_stateShoot) << std::endl;
			_previousStateShoot = _stateShoot;
		}

	}
    return 0;
}

