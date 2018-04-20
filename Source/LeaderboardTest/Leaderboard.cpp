#include"Leaderboard.h"

using namespace PlayFab;
using namespace ClientModels;



Leaderboard* Leaderboard::Create() {
	
	PlayFabSettings::titleId = WidenString("EFAC");

	return new Leaderboard();
}


void Leaderboard::Login(const std::string& customID) {

	LoginWithCustomIDRequest request;
	request.CreateAccount = false;
	request.CustomId = customID;

	PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnFail);
}


void Leaderboard::Register(const std::string& customID) {

	LoginWithCustomIDRequest request;
	request.CreateAccount = true;
	request.CustomId = customID;

	PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnFail);

}

void Leaderboard::UpdatePlayerStatistics(const int statisticValue) {

	UpdatePlayerStatisticsRequest request;

	StatisticUpdate stat;
	stat.StatisticName = "Top Scores";
	stat.Value = statisticValue;

	const std::list<StatisticUpdate> statistics = { stat };
	request.Statistics = statistics;

	PlayFabClientAPI::UpdatePlayerStatistics(request, OnPlayerStatisticsUpdateSuccess, OnFail);

	while (PlayFabClientAPI::Update() != 0)
		Sleep(1);
}

void Leaderboard::UpdateUserTitleDisplayName(const std::string& name) {

	UpdateUserTitleDisplayNameRequest request;
	request.DisplayName = name;

	PlayFabClientAPI::UpdateUserTitleDisplayName(request, OnNameUpdateSuccess, OnFail);

	while (PlayFabClientAPI::Update() != 0)
		Sleep(1);
}

std::list<PlayFab::ClientModels::PlayerLeaderboardEntry>& Leaderboard::GetLeaderboard() {

	GetLeaderboardRequest request;
	request.StatisticName = "Top Scores";

	PlayFabClientAPI::GetLeaderboard(request, OnGetLeaderboardSuccess, OnFail);

	while (PlayFabClientAPI::Update() != 0)
		Sleep(1);


	return leaderboard;
}


void OnLoginSuccess(const LoginResult& result, void* customData) {
	std::cout << "Logged in" << std::endl;
}

void OnPlayerStatisticsUpdateSuccess(const UpdatePlayerStatisticsResult& result, void* customData) {
	std::cout << "Player statistic was updated" << std::endl;
}

void OnGetLeaderboardSuccess(const GetLeaderboardResult& result, void* customData) {

	leaderboard = result.Leaderboard;
	std::cout << "Operation success" << std::endl;
}

void OnNameUpdateSuccess(const UpdateUserTitleDisplayNameResult& result, void* customData) {
	std::cout << "User title was updated" << std::endl;
}

void OnFail(const PlayFabError& error, void* customData) {
	std::cerr << "Error occured: " << error.GenerateReport() << std::endl;
}