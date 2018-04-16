#pragma once
#include"playfab\PlayFabAdminAPI.h"
#include"playfab\PlayFabSettings.h"
#include<iostream>
#include<map>


class LeaderBoard final {

private:
	
	
	std::map<std::string, std::string> scores;

	LeaderBoard() {}


public:

	static LeaderBoard* Create();
	void CreatePlayerStatisticDefinition();
	void UpdatePlayerStatisticDefinition();
	void GetPlayerStatisticDefinitions();

};