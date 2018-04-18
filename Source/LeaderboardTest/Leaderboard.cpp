#include"Leaderboard.h"

using namespace PlayFab;
using namespace ClientModels;



Leaderboard* Leaderboard::Create() {
	
	return new Leaderboard();
}


void Leaderboard::Login(std::string customID) {

	LoginWithCustomIDRequest request;
	request.CustomId = customID;

	PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnFail);
}


void Leaderboard::Register(std::string customID) {

	LoginWithCustomIDRequest request;
	request.CreateAccount = true;
	request.CustomId = customID;

	PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnFail);

}

void Leaderboard::UpdatePlayerStatistics() {

	UpdatePlayerStatisticsRequest request;

	PlayFabClientAPI::UpdatePlayerStatistics(request, OnUpdateSuccess, OnFail);
}


void Leaderboard::GetLeaderboard() {

	GetLeaderboardRequest request;
	request.StatisticName = "Top Score";

	PlayFabClientAPI::GetLeaderboard(request, OnSuccess, OnFail);
}


void OnLoginSuccess(const PlayFab::ClientModels::LoginResult& result, void* customData) {
	std::cout << "Login operation success" << std::endl;
}

void OnUpdateSuccess(const PlayFab::ClientModels::UpdatePlayerStatisticsResult& result, void* customData) {
	std::cout << "Update operation success" << std::endl;
}
void OnSuccess(const PlayFab::ClientModels::GetLeaderboardResult& result, void* customData) {
	std::cout << "Operation success" << std::endl;
}
void OnFail(const PlayFab::PlayFabError& error, void* customData) {
	std::cerr << "Error occured: " << error.GenerateReport() << std::endl;
}