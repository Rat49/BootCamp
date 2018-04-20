#include"Leaderboard.h"


int main() {

	Leaderboard *l = Leaderboard::Create();

	l->Login("okkkk");
	l->Register("ookkk");
	l->Login("ookkk");

	l->GetLeaderboard();
	l->leaderboard;


	if (l != NULL) {
		delete l;
	}

	return 0;
}