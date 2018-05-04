#pragma once

#include"playfab/PlayFabClientAPI.h"
#include"playfab/PlayFabClientDataModels.h"
#include"playfab/PlayFabSettings.h"

#include<iostream>
#include<windows.h>


class Leaderboard final {

private:
	
	Leaderboard(){}
	

public:

	std::list<PlayFab::ClientModels::PlayerLeaderboardEntry> leaderboard;


	static Leaderboard* Create();

	void Login(const std::string& customID, bool createAccount=false);
	void UpdatePlayerStatistic(const int statisticValue);
	void UpdateUserTitleDisplayName(const std::string& name);
	void UpdateLocalLeaderboard();
	std::list<PlayFab::ClientModels::PlayerLeaderboardEntry> GetLeaderboard();

};

void OnLoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData);
void OnPlayerStatisticsUpdateSuccess(const PlayFab::ClientModels::UpdatePlayerStatisticsResult& result, void* customData);
void OnNameUpdateSuccess(const PlayFab::ClientModels::UpdateUserTitleDisplayNameResult& result, void* customData);
void OnFail(const PlayFab::PlayFabError& error, void* customData);