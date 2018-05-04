#pragma once

#include"playfab/PlayFabClientAPI.h"
#include"playfab/PlayFabClientDataModels.h"
#include"playfab/PlayFabSettings.h"

#include "EventSystem.h"
#include "Asteroid.h"
#include "Rocket.h"
#include "CollisionEvent.h"

#include<iostream>
#include<windows.h>


class Leaderboard final {

private:
	
	Leaderboard();
	int score;

public:

	std::list<PlayFab::ClientModels::PlayerLeaderboardEntry> leaderboard;

	Token_t _tokenForCollisionEventBetweenAmmunitionAndSpaceship;
	Token_t _tokenForCollisionEventBetweenAsteroidAndBullet;
	Token_t _tokenForCollisionEventBetweenAsteroidAndRocket;


	static Leaderboard* Create();

	void Login(const std::string& customID, bool createAccount = false);
	void UpdatePlayerStatistic(const int statisticValue);
	void UpdateUserTitleDisplayName(const std::string& name);
	void UpdateLocalLeaderboard();

	void OnAmmunitionCollisionHandler(const Event & cEvent);
	void OnBulletCollisionHandler(const Event & cEvent);
	void OnRocketCollisionHandler(const Event & cEvent);
	void Scoring(AsteroidType type);
	int GetScore();
	void SetScore(int arg);
};

void OnLoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData);
void OnPlayerStatisticsUpdateSuccess(const PlayFab::ClientModels::UpdatePlayerStatisticsResult& result, void* customData);
void OnNameUpdateSuccess(const PlayFab::ClientModels::UpdateUserTitleDisplayNameResult& result, void* customData);
void OnFail(const PlayFab::PlayFabError& error, void* customData);