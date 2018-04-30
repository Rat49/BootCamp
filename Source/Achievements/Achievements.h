#pragma once
#include <string>
#include <ctime>
#include <map>

class Achievement
{
public:
	Achievement(std::multimap<const std::string, const std::string>& AchievementList);
	~Achievement();

	int GetIdAchievement() const;
	float GetProgressState() const;
	float GetProgressFinishState() const;
	const std::string& GetDisplayName() const;
	const std::string& GetDisplayDescriptionName() const;
	const std::string& GetDateCompleteAchievements() const;
	bool GetAchievedActive() const;

	void SetIdAchievement(int id);
	void SetProgressState(float state);
	void SetProgressFinishState(float state);
	void SetDisplayName(const std::string& name);
	void SetDisplayDescriptionName(const std::string& name);
	void SetDateCompleteAchievements(const std::string& dateCompleteAchievements);
	void SetAchievedActive(bool active);

private:
	int _idAchievement;
	float _progressState;
	float _progressFinishState;
	std::string _displayName;
	std::string _displayDescriptionName; //27
	std::string _dateCompleteAchievements;
	bool _achievedActive;
};
