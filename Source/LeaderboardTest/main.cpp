#include"Leaderboard.h"


namespace LeaderboardTest {


	void Test() {

		Leaderboard *l = Leaderboard::Create();

		std::cout << "Login and register test:" << std::endl;
		std::cout << "Register:" << std::endl;
		l->Register("ok");
		std::cout << "Wrong login:" << std::endl;
		l->Login("okkkk");
		std::cout << "Correct login:" << std::endl;
		l->Login("ok");

		std::cout << "Update user name test:" << std::endl;
		l->UpdateUserTitleDisplayName("ok1");
		std::cout << "Update player statistic test:" << std::endl;
		l->UpdatePlayerStatistic(1000);

		std::cout << "Get updated leaderboard test:" << std::endl;
		l->UpdateLocalLeaderboard();
		l->leaderboard;


		if (l != NULL) {
			delete l;
		}

	}


	int main() {

		Test();

		return 0;
	}

}