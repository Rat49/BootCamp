#include "Achievements.h"

Achievement::Achievement(std::multimap<const std::string, const std::string>& AchievementList)
{
	_idAchievement = atoi(AchievementList.find("_idAchievement")->second.c_str());
	_progressState = atof(AchievementList.find("_progressState")->second.c_str());
	_progressFinishState = atof(AchievementList.find("_progressFinishState")->second.c_str());
	_displayName = AchievementList.find("_displayName")->second;
	_displayDescriptionName = AchievementList.find("_displayDescriptionName")->second;
	_achievedActive = atoi(AchievementList.find("_achievedActive")->second.c_str());
	_dateCompleteAchievements = atoi(AchievementList.find("_dateCompleteAchievements")->second.c_str());
}

int Achievement::GetIdAchievement() const
{
	return _idAchievement;
}

float Achievement::GetProgressState() const 
{
	return _progressState;
}

float Achievement::GetProgressFinishState() const
{
	return _progressFinishState;
}

const std::string& Achievement::GetDisplayName() const
{
	return _displayName;
}

const std::string& Achievement::GetDisplayDescriptionName() const
{
	return _displayDescriptionName;
}

bool Achievement::GetAchievedActive() const
{
	return _achievedActive;
}

const std::string & Achievement::GetDateCompleteAchievements() const
{
	return _dateCompleteAchievements;
}

void Achievement::SetIdAchievement(int id)
{
	_idAchievement = id;
}

void Achievement::SetProgressState(float state)
{
	_progressState = state;
}

void Achievement::SetProgressFinishState(float finishState)
{
	_progressFinishState = finishState;
}

void Achievement::SetDisplayName(const std::string& name)
{
	_displayName = name;
}

void Achievement::SetDisplayDescriptionName(const std::string& descriptionName)
{
	_displayDescriptionName = descriptionName;
}

void Achievement::SetAchievedActive(bool active)
{
	_achievedActive = active;
}

void Achievement::SetDateCompleteAchievements(const std::string& dateCompleteAchievements)
{
	_dateCompleteAchievements = dateCompleteAchievements;
}
