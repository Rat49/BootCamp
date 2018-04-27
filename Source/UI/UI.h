#include <string>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include "Widget.h"

struct PercentXY
{
	PercentXY(const float x, const float y) : _x(x), _y(y)
	{
		if (x < 0 || x > 100 || y < 0 || y > 100)
		{
			//Log?
			_x = 0;
			_y = 0;
		}
	}

	float _x;
	float _y;
};

class UI final
{
public:
	UI(sf::RenderWindow& window);
	~UI();

	template<typename T>
	T* Get(const std::string& key) 
	{
		return dynamic_cast<T*>(GetWidget(key));
	}

	void OnResize();
	void Render();
	void OnAchive(const std::string& text, sf::Image* picture);
	void SetPostion(const std::string& key, const PercentXY relCoord);
	sf::Vector2f GetPosition(const std::string& key);	

	Widget* CreateButton(const sf::Vector2f size, const PercentXY relativePos, const std::string& name);
	Widget* CreateLabel(const std::string& content, const sf::Font& font, const PercentXY relativePos, const std::string& name);
	Widget* CreateScrollBar(const float length, const PercentXY relativePos, const std::string& name);
	Widget* CreateAchivementShower(const sf::Font& font, const PercentXY relPos);

	void RemoveWidget(const std::string& key);

private:	
	const sf::Vector2f RelativeCordToAbs(const PercentXY relCoord) const;
	Widget* GetWidget(const std::string &key);

	sf::RenderWindow& _window;
	std::map<std::string, Widget*> _widgets;
};


