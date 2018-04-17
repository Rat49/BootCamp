#include"LeaderBoard.h"

using namespace PlayFab;
using namespace ClientModels;
//using namespace AdminModels;


Leaderboard* Leaderboard::Create() {
	
	return new Leaderboard();

}
/*
void LeaderBoard::CreatePlayerStatisticDefinition() {
	/*
	CreatePlayerStatisticDefinitionRequest request;
	request.StatisticName = "Top Score";
	request.VersionChangeInterval = StatisticResetIntervalOption::StatisticResetIntervalOptionWeek;

	ProcessApiCallback<CreatePlayerStatisticDefinitionResult> callback;

	PlayFabAdminAPI::CreatePlayerStatisticDefinition(request, callback);
}

void LeaderBoard::UpdatePlayerStatisticDefinition() {

}
*/

void Leaderboard::LoginWithCustomID() {

	LoginWithCustomIDRequest request;

	//PlayFabClientAPI::LoginWithCustomID(request, callback, errorCallback);
}

void Leaderboard::LoginWithEmailAddress(std::string emailAddress) {

	LoginWithEmailAddressRequest request;
	request.Email = emailAddress;
	ProcessApiCallback<LoginResult> callback;
	ErrorCallback errorCallback;

	PlayFabClientAPI::LoginWithEmailAddress(request, callback, errorCallback);
}

void Leaderboard::Register() {

}

void Leaderboard::GetLeaderboard() {

	GetLeaderboardRequest request;
	request.StatisticName = "Top Score";

	ProcessApiCallback<GetLeaderboardResult> callback;
	ErrorCallback errorCallback;

	PlayFabClientAPI::GetLeaderboard(request, callback, errorCallback);
}