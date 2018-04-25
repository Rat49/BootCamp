#pragma once
#include <string>
#include <ctime>

class Achievement
{
public:
	Achievement();
	~Achievement();

	int GetIdAchievement() const;
	float GetProgressState() const;
	float GetProgressFinishState() const;
	const std::string& GetDisplayName() const;
	const std::string& GetDisplayDescriptionName() const;
	bool GetAchievedActive() const;

	void SetIdAchievement(int id);
	void SetProgressState(float state);
	void SetProgressFinishState(float state);
	void SetDisplayName(const std::string& name);
	void SetDisplayDescriptionName(const std::string& name);
	void SetAchievedActive(bool active);

private:
	int _idAchievement;
	float _progressState;
	float _progressFinishState;
	std::string _displayName;
	std::string _displayDescriptionName;
	bool _achievedActive;
	time_t _dateCompleteAchievements;
};
