#pragma once
#include <map>
#include <SFML\Window.hpp>

enum class GameActions {
	Up,
	Down,
	Left,
	Right,
	Escape,
	Enter,
	Space
};

enum class ButtonsState {
	JustPressed,
	Pressed,
	JustReleased,
	Released
};

class InputManager
{
private:
	std::map<int, int> buttonsState;
public:
	std::map<int, int> GetState() const;
	std::map<int,int> buttonsKey;
	int ChangeStateWhenRelease(int);
	int ChangeStateWhenPressed(int);
	void Update();
	InputManager(const std::map<int, int>& arr);
	~InputManager();
};
