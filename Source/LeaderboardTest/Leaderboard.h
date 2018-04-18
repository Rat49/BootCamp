#pragma once

#include"playfab\PlayFabClientAPI.h"

#include<iostream>


class Leaderboard final {

private:
	
	Leaderboard() {}


public:

	static Leaderboard* Create();

	void Login(std::string);
	void Register(std::string);
	void UpdatePlayerStatistics();
	void GetLeaderboard();

};


void OnLoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData);
void OnUpdateSuccess(const PlayFab::ClientModels::UpdatePlayerStatisticsResult& result, void* customData);
void OnSuccess(const PlayFab::ClientModels::GetLeaderboardResult& result, void* customData);
void OnFail(const PlayFab::PlayFabError& error, void* customData);