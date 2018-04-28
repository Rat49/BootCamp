#pragma once
#include "DebugConsoleKeyEvent.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <map>

using Action_t = int;
using ButtonKey_t = int;

enum class GameActions {
	MoveUp,
	MoveDown,
	MoveLeft,
	MoveRight,
	Exit,
	Choose,
	Shoot,
	SuperShoot,
	Console,
	Pause
};

enum class ButtonsState 
{
	JustPressed,
	Pressed,
	JustReleased,
	Released,
	Block
};

enum class InputMode 
{
	Normal,
	Raw,
	Paused,
	PausedRaw
};

class InputManager final
{
private:
	InputMode _mode = InputMode::Normal;
	sf::Event _keyEvent;
	
	struct localButtonsConfig 
	{
		Action_t action;
		ButtonsState state;
		ButtonKey_t primary;
		ButtonKey_t alternatively;
	};

	std::vector<localButtonsConfig> buttonsState;
	ButtonsState ChangeStateWhenReleased(ButtonsState);
	ButtonsState ChangeStateWhenPressed(ButtonsState);

public:
	bool GetState(const Action_t searchAction, ButtonsState& result) const;
	InputMode GetMode() const;
	void Update();
	void ConsoleMode();
	void PausedMode();
	void HandleRawEvent(const sf::Event& event);
	InputManager(const std::multimap<Action_t, ButtonKey_t>& arr);
	InputManager();
};
