#include "Achievements.h"
#include "ConfigManager.h"
#include <cstdlib>
#include <conio.h>


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

void	UnlockAchievement()
{

}

void	ConditionAchievement()
{

}

void	ViewCollectionAchievement()
{

}
void	ViewUnlockAchievement()
{

}

int main()
{
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
