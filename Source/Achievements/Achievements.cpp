#include "Achievements.h"

Achievement::Achievement()
{
}

Achievement::~Achievement()
{
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
