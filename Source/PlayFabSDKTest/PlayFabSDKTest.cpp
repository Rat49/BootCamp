#include "playfab/PlayFabClientDataModels.h"
#include "playfab/PlayFabClientApi.h"
#include "playfab/PlayFabSettings.h"
#include <windows.h>

using namespace PlayFab;
using namespace ClientModels;

bool finished = false;

void OnLoginSuccess(const LoginResult & result, void * customData)
{
  printf("Congratulations, you made your first successful API call!\n");
  finished = true;
}

void OnLoginFail(const PlayFabError & error, void * customData)
{
  printf("Something went wrong with your first API call.\n");
  printf("Here's some debug information:\n");
  printf(error.GenerateReport().c_str());
  printf("\n");
  finished = true;
}

int main()
{
  PlayFabSettings::titleId = WidenString("144");

  LoginWithCustomIDRequest request;
  request.CreateAccount = true;
  request.CustomId      = "GettingStartedGuide";

  PlayFabClientAPI::LoginWithCustomID(request, OnLoginSuccess, OnLoginFail);


  while(PlayFabClientAPI::Update() != 0)
    Sleep(1);

  printf("Press enter to exit\n");
  getchar();
  return 0;
}
