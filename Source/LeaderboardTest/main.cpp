#include"Leaderboard.h"


namespace LeaderboardTest {


	void Test() {

		Leaderboard *l = Leaderboard::Create();
		bool createAccount = true;

		std::cout << "Login and register test:" << std::endl;
		std::cout << "Register:" << std::endl;
		l->Login("123", createAccount);

		std::cout << "Wrong login:" << std::endl;
		l->Login("1234");
		std::cout << "Correct login:" << std::endl;
		l->Login("123");

		std::cout << "Update user name test:" << std::endl;
		l->UpdateUserTitleDisplayName("1234");
		std::cout << "Update player statistic test:" << std::endl;
		l->UpdatePlayerStatistic(4000);

		std::cout << "Get updated leaderboard test:" << std::endl;
		l->UpdateLocalLeaderboard();
		l->leaderboard;


		/*if (l != NULL) {
			delete l;
		}*/

	}

}
int main() {

	LeaderboardTest::Test();

	int a;
	std::cin >> a;
	return 0;
}