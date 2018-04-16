#include"LeaderBoard.h"


int main() {

	LeaderBoard *leaderboard = LeaderBoard::Create();

	if (leaderboard != NULL) {
		delete leaderboard;
	}

	return 0;
}