#pragma once
#include <vector>

using std::vector;

class Board
{
private:
	vector<vector<char> > board;
	int m, n;
	bool turn,won;
	char player, oponent;
	int multiplayer;
	int checkVictory();
	void turnAndPlay();
	void turnAndPlayRandom();
	void turnAndplayAI();
	int minMaxAlgo(int turn, int depth);
	void findBestMove();
	bool isBoardFill();
	void printBoard();

public:
	Board(int multiplayer,int m,int n);
	bool whoWon() { return won; }
	void checkPlayerType();
};

