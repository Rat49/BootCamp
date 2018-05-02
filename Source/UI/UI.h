#include "SfmlButton.h"
#include "Label.h"
#include "ScrollBar.h"
#include "AchievementShower.h"
#include "Widget.h"
#include "Picture.h"
#include "Event.h"
#include "Dispatcher.h"
#include "UpdateSpaceshipStateEvent.h"
#include <cassert>

struct PercentXY
{
	PercentXY(const float x, const float y)
	{
		if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
		{
			_x = x;
			_y = y;
		}
		else
		{
			//Log?
			_x = 0;
			_y = 0;
		}
	}
	float _x;
	float _y;
};

struct cmpByString
{
	bool operator()(const std::string& a, const std::string& b) const
	{
		return a < b;
	}
};
class UI final
{
public:
	UI(sf::RenderWindow & window);
	void OnChangedSpaceshipStorage(const Event & event);
	template<typename T>
	T* Get(const std::string& key) 
	{
		Widget* wid = GetWidget(key);
		T* specificWidget = dynamic_cast<T*>(wid);
		return specificWidget;
	}
	Token_t _tokenUI;
	Token_t _tokenWeaponUI;
	void OnChangedSpaceshipState(const Event & event);
	void OnResize();
	void Render();
	void OnAchive(const std::string & name, const std::string & description,sf::Image * picture);
	void SetPostion(const std::string& key, const PercentXY relCoord);
	sf::Vector2f GetPosition(const std::string& key);	

	Widget * CreateButton(const sf::Vector2f size, const PercentXY relativePos, const std::string & name);
	Widget * CreateLabel(const std::string & content, const sf::Font & font, const PercentXY relativePos, const std::string & name);
	Widget * CreateScrollBar(const float length, const PercentXY relativePos, const std::string & name);
	Widget * CreateAchivementShower(const sf::Font & font, const PercentXY relativePos);
	Widget * CreatePicture(const sf::Image & img, const PercentXY relativePos, const std::string & name);

	void RemoveWidget(const std::string & key);

	~UI();
private:	
	
	const sf::Vector2f RelativeCordToAbs(const PercentXY relCoord) const;
	sf::RenderWindow & _window;
	Widget* GetWidget(const std::string &key);
	std::map<std::string, Widget*, cmpByString> _widgets;
	
};


