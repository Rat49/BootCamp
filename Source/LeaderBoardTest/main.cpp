#include"LeaderBoard.h"


int main() {

	Leaderboard *leaderboard = Leaderboard::Create();

	if (leaderboard != NULL) {
		delete leaderboard;
	}

	return 0;
}