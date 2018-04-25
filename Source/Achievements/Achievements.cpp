#include "Achievements.h"
#include "ConfigManager.h"
#include "EventSystem.h"
#include "EventForAchiev.h"
#include "Physics.h"
#include "UI.h"
#include <cstdlib>

Achievement::Achievement()
{

}

Achievement::~Achievement()
{

}

int		Achievement::GetIdAchievement() { return _idAchievement; }
float	Achievement::GetProgressState() { return _progressState; }
float	Achievement::GetProgressFinishState() { return _progressFinishState; }
std::string Achievement::GetDisplayName() { return _displayName; }
std::string Achievement::GetDisplayDescriptionName() { return _displayDescriptionName; }
bool	Achievement::GetAchievedActive() { return _achievedActive; }

void	Achievement::SetIdAchievement(int id) { _idAchievement = id; }
void	Achievement::SetProgressState(float state) { _progressState = state; }
void	Achievement::SetProgressFinishState(float finishState) { _progressFinishState = finishState; }
void	Achievement::SetDisplayName(std::string name) { _displayName = name; }
void	Achievement::SetDisplayDescriptionName(std::string descriptionName) { _displayDescriptionName = descriptionName; }
void	Achievement::SetAchievedActive(bool active) { _achievedActive = active; }

void	ConditionAchievement(Achievement *achieves, int num, sf::RenderWindow window)
{
	for (int i = 1; i < maxEventID; ++i)
	{
		if (achieves[i].GetAchievedActive() == false)
		{
			std::map<EventAchievID_t, Token_t> _tokens;
			int countOfHandlerResponce = achieves[i - 1].GetProgressState();
			std::map<EventAchievID_t, Token_t>::iterator tokenForCurrentEvent = _tokens.find(i);
			std::function<void(const Event&)> handler = [&](const Event &e)
			{
				achieves[i - 1].SetProgressState(++countOfHandlerResponce);
				if (achieves[i].GetProgressFinishState() == achieves[i].GetProgressState())
				{
					achieves[i].SetAchievedActive(true);
					UI mui(window);
					sf::Font font;
					font.loadFromFile("font/arial.ttf");
					mui.CreateAchivementShower(font, PercentXY(80, 80));
					sf::Image * img = new sf::Image();
					img->loadFromFile("img/asteroid.png");
					mui.OnAchive(achieves[num].GetDisplayName(), img);
				}
			};
		}
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Asteroids");
	sf::Event sysEvent;

	ConfigManager* achievCM = ConfigManager::Create("testAchievement.INI");
	int num = atoi((achievCM->GetCategory("NUM_ACHIEVEMENT").GetValue("_numAchievements")).c_str());
	std::cout << num;
	Achievement *achieves = new Achievement[num];
	for (int i = 0; i < num; ++i) 
	{
		std::string str = std::to_string(i);
		achieves[i].SetIdAchievement(atoi((achievCM->GetCategory(str).GetValue("_idAchievement")).c_str()));
		achieves[i].SetProgressState(atof((achievCM->GetCategory(str).GetValue("_progressState")).c_str()));
		achieves[i].SetProgressFinishState(atof((achievCM->GetCategory(str).GetValue("_progressFinishState")).c_str()));
		achieves[i].SetDisplayName((achievCM->GetCategory(str).GetValue("_displayName")).c_str());
		achieves[i].SetDisplayDescriptionName((achievCM->GetCategory(str).GetValue("_displayDescriptionName")).c_str());
		achieves[i].SetAchievedActive(atoi((achievCM->GetCategory(str).GetValue("_achievedActive")).c_str()));
	}
	delete[]achieves;
	delete achievCM;
}
