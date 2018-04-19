#pragma once

#include"playfab\PlayFabClientAPI.h"
#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabSettings.h"

#include<iostream>
#include<windows.h>


class Leaderboard final {

private:

	bool finished;
	std::list<PlayFab::ClientModels::PlayerLeaderboardEntry> leaderboard;
	
	Leaderboard(): finished(false) {}


public:

	static Leaderboard* Create();

	void Login(const std::string& customID);
	void Register(const std::string& customID);
	void UpdatePlayerStatistics(const int statisticValue);
	void UpdateUserTitleDisplayName(const std::string& name);
	std::list<PlayFab::ClientModels::PlayerLeaderboardEntry>& GetLeaderboard();

};


void OnLoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData);
void OnPlayerStatisticsUpdateSuccess(const PlayFab::ClientModels::UpdatePlayerStatisticsResult& result, void* customData);
void OnGetLeaderboardSuccess(const PlayFab::ClientModels::GetLeaderboardResult& result, void* customData);
void OnNameUpdateSuccess(const PlayFab::ClientModels::UpdateUserTitleDisplayNameResult& result, void* customData);
void OnFail(const PlayFab::PlayFabError& error, void* customData);