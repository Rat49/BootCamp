#pragma once

//#include"playfab\PlayFabAdminAPI.h"
#include"playfab\PlayFabClientAPI.h"
//#include"playfab\PlayFabSettings.h"

#include<iostream>


class Leaderboard final {

private:
	

	Leaderboard() {}


public:

	static Leaderboard* Create();

	//void CreatePlayerStatisticDefinition();
	//void UpdatePlayerStatisticDefinition();

	//void Login(int method);
	void LoginWithCustomID();
	void LoginWithEmailAddress(std::string emailAddress);
	void Register();
	void GetLeaderboard();

};