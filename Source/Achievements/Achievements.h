#pragma once
#include <string>
#include <ctime>

class Achievement {
private:
	int		_idAchievement;
	float	_progressState;
	float	_progressFinishState;
	std::string _displayName;
	std::string _displayDescriptionName;
	bool	_achievedActive;
	time_t	_dateCompleteAchievements;
public:
	Achievement();
	~Achievement();
	int		GetIdAchievement();
	float	GetProgressState();
	float	GetProgressFinishState();
	std::string GetDisplayName();
	std::string GetDisplayDescriptionName();
	bool	GetAchievedActive();

	void	SetIdAchievement(int);
	void	SetProgressState(float);
	void	SetProgressFinishState(float);
	void	SetDisplayName(std::string);
	void	SetDisplayDescriptionName(std::string);
	void	SetAchievedActive(bool);
};
