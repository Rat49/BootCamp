#include "SfmlButton.h"
#include "Label.h"
#include "ScrollBar.h"
#include "Widget.h"
#include <cassert>

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
	template<typename T>
	T* Get(const std::string& key)
	{
		Widget* wid = GetWidget(key);
		T* specificWidget = dynamic_cast<T*>(wid);
		return specificWidget;
	}

	void OnResize();
	void Render();
	void SetPostion(const std::string& key, sf::Vector2f relCoord);
	sf::Vector2f GetPosition(const std::string& key);	

	Widget * CreateButton(const sf::Vector2f size, const sf::Vector2f relativePos, const std::string & name);
	Widget * CreateLabel(const std::string & content, const sf::Font & font, const sf::Vector2f relativePos, const std::string & name);
	Widget * CreateScrollBar(const float length, const sf::Vector2f relativePos, const std::string & name);

	~UI();
private:	
	sf::Vector2f RelativeCordToAbs(sf::Vector2f relCoord);
	sf::RenderWindow & _window;
	Widget* GetWidget(const std::string &key);
	std::map<std::string, Widget*, cmpByString> _widgets;
	
};


