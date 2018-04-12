#include "SfmlButton.h"
#include "Label.h"
#include "ScrollBar.h"
#include <SFML\Graphics.hpp>
#include <cassert>
#include <memory>

struct cmpByStringLength
{
	bool operator()(const std::string& a, const std::string& b) const
	{
		return a < b;
	}
};

class UI //:
	//public sf::RenderWindow
{
public:
	UI(sf::VideoMode screen,const std::string & name);

	template<typename T>
	T* Get(const std::string& key)
	{
		Widget* wid = GetWidget(key);
		T* specificWidget = dynamic_cast<T*>(wid);
		return specificWidget;
	}

	void onResize();
	void Render();

	void SetPostion(const std::string& key, float x, float y);
	sf::RenderWindow _space;
	void Add(Widget * wid, const std::string &name);
	~UI();
private:
	sf::Vector2u _oldSize;
	Widget* GetWidget(const std::string &key);
	std::map<std::string, Widget*, cmpByStringLength> _widgets;
	
};


