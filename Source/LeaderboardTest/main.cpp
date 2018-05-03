#include"Leaderboard.h"
#include <conio.h>

namespace LeaderboardTest {


	void Test() {

		Leaderboard *l = Leaderboard::Create();
		bool createAccount = true;

		std::cout << "Login and register test:" << std::endl;
		std::cout << "Register:" << std::endl;
		std::string customID;
		std::cin >> customID;
		l->Login(customID, createAccount);

		//std::cout << "Wrong login:" << std::endl;
		//l->Login("nikitaokkkkk");
		std::cout << "Correct login:" << std::endl;
		l->Login(customID);

		std::cout << "Update user name test:" << std::endl;
		std::string userTitleDisplayName;
		std::cin >> userTitleDisplayName;
		l->UpdateUserTitleDisplayName(userTitleDisplayName);
		std::cout << "Update player statistic test:" << std::endl;
		int score = 0;
		l->UpdatePlayerStatistic(score);

		std::cout << "Get updated leaderboard test:" << std::endl;
		l->UpdateLocalLeaderboard();
		l->leaderboard;

		for (auto v : l->leaderboard) {
			std::cout << v.DisplayName << std::endl;
			std::cout << v.StatValue << std::endl;
		}


		if (l != NULL) {
			delete l;
		}

		_getch();

	}

}

int main() {

	LeaderboardTest::Test();

	return 0;
}