#pragma once
#include "SfmlButton.h"

class ScrollBar :
	public SfmlButton
{
public:
	ScrollBar(const float length, const sf::Vector2f pos, const std::string & name);
	void ChangeStateGrab(sf::Vector2i position);
	void UpdatePosition();
	//void UpdateControl() override;
	void Draw() override;


	~ScrollBar();
private:
	bool _isGrab;
	std::pair<int, int> _bounds;
};

