#include"Leaderboard.h"

using namespace PlayFab;
using namespace ClientModels;



Leaderboard* Leaderboard::Create() {
	
	PlayFabSettings::titleId = WidenString("EFAC");
	
	return new Leaderboard();
}

void Leaderboard::Login(const std::string& customID, bool createAccount)
{
	LoginWithCustomIDRequest request;
	request.CreateAccount = createAccount;
	request.CustomId = customID;

	PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnFail);

	while (PlayFabClientAPI::Update() != 0)
		Sleep(1);
}

void Leaderboard::UpdatePlayerStatistic(const int statisticValue) {

	UpdatePlayerStatisticsRequest request;

	StatisticUpdate stat;
	stat.StatisticName = "Top Scores";
	stat.Value = statisticValue;

	const std::list<StatisticUpdate> statistics = { stat };
	request.Statistics = statistics;

	PlayFabClientAPI::UpdatePlayerStatistics(request, OnPlayerStatisticsUpdateSuccess, OnFail);

	while (PlayFabClientAPI::Update() != 0)
		Sleep(50);
}

void Leaderboard::UpdateUserTitleDisplayName(const std::string& name) {

	UpdateUserTitleDisplayNameRequest request;
	request.DisplayName = name;

	PlayFabClientAPI::UpdateUserTitleDisplayName(request, OnNameUpdateSuccess, OnFail);

	while (PlayFabClientAPI::Update() != 0)
		Sleep(1);
}

std::list<PlayFab::ClientModels::PlayerLeaderboardEntry> Leaderboard::GetLeaderboard()
{
	for (auto i : leaderboard)
	{
		std::cout << i.DisplayName << "\t\t" << i.StatValue << std::endl;
	}
	return leaderboard;
}
void Leaderboard::UpdateLocalLeaderboard() {

	GetLeaderboardRequest request;
	request.StatisticName = "Top Scores";

	PlayFabClientAPI::GetLeaderboard(request, [this](const GetLeaderboardResult& result, void* /*customData*/) { 

		leaderboard = result.Leaderboard;

	}, OnFail);
	
	while (PlayFabClientAPI::Update() != 0)
		Sleep(1);
}

void OnLoginSuccess(const LoginResult& /*result*/, void* /*customData*/) {
}

void OnPlayerStatisticsUpdateSuccess(const UpdatePlayerStatisticsResult& /*result*/, void* /*customData*/) {
}

void OnNameUpdateSuccess(const UpdateUserTitleDisplayNameResult& /*result*/, void* /*customData*/) {
}

void OnFail(const PlayFabError& error, void* /*customData*/) {
	std::cerr << "Error occured: " << error.GenerateReport() << std::endl;
}