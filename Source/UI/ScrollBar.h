#pragma once
#include <SFML\Graphics.hpp>
#include "SfmlButton.h"

class ScrollBar final :	public SfmlButton
{
public:
	ScrollBar(const float length, const sf::Vector2f position, const std::string& name, sf::RenderWindow& owner);
	~ScrollBar();

	void ChangeStateGrab(const sf::Vector2i position);
	void UnGrab();
	void SetSliderPosition(const float position);
	float GetSliderPosition() const;
	
	void SetFillColor(const sf::Color& color) override;
	void SetOutlineColor(const sf::Color& color) override;
	void SetLength(const float size);

	float GetLength() const;

	void OnResize() override;
	void Draw() override;

private:
	void operator=(const ScrollBar&) = delete;
	ScrollBar(const ScrollBar&) = delete;

	float _sliderValue;
	void UpdatePosition();
	bool _isGrabbed;
	sf::RectangleShape _rail;
};

