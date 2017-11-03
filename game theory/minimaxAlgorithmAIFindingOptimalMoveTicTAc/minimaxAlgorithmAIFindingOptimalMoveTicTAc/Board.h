#pragma once
#pragma warning(disable:4996)

class Board
{
private:
	bool move;
	char board[3][3];
	int m, n;
	char player, oponent;
	bool isMovesLeft();
	int evaluate();
	int minimax(int depth, bool turn);
	
public:
	int row, col, won;
	Board(char b[][3],int row,int col);
	void findBestMove();
	void fillBoard();
	void printBoard();
};

