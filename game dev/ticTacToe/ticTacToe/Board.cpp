#include "stdafx.h"
#include "Board.h"

#include <algorithm>
#include <random>
#include <iostream>
#include <ctime>
#include <climits>

using std::cout;
using std::endl;
using std::cin;

Board::Board(int multiplayer,int m,int n)
{
	this->multiplayer = multiplayer;
	this->m = m;
	this->n = n;
	player = 'x';
	oponent = 'o';
	board = vector<vector<char> >(m, vector<char>(n, '_'));
}

void print(char i) {
	cout << i << " ";
}

void Board::printBoard()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool Board::isBoardFill() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '_')
				return false;
		}
	}
	return true;
}

int Board::checkVictory()
{
	//for each row an column
	for (int i = 0; i < m; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			if(board[i][0] == player)
				return -10;
			if (board[i][0] == oponent)
				return +10;
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && (board[0][i] == player || board[0][i] == oponent)) {
			if (board[0][i] == player)
				return -10;
			if (board[0][i] == oponent)
				return +10;
		}
	}
	//for diagonal
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
		if (board[1][1] == player)
			return -10;
		if (board[1][1] == oponent)
			return +10;
	}
	return 0;
}

void Board::checkPlayerType() {
	switch (multiplayer) {
	case 1:
		turnAndPlay();
		break;
	case 2:
		turnAndPlayRandom();
		break;
	case 3:
		turnAndplayAI();
		break;
	default:
		cout << "wrong choice" << endl;
	}
}

void Board::turnAndPlay()
{
	printBoard();
	turn = true;
	while (true) {
		int row, col;
		cout << "Row and Col:: " << endl;
		cin >> row >> col;
		if (turn)
			board[row][col] = player;
		if(!turn)
			board[row][col] = oponent;
		turn = !turn;
		printBoard();
		if (checkVictory()) {
			if (!turn) {
				cout << "PLAYER WONN!!!" << endl;
				break;
			}
			if (turn) {
				cout << "OPONENT WONN!!!" << endl;
				break;
			}
		}
		if (isBoardFill()) {
			cout << "DRAWWW!!!!" << endl;
			break;
		}
	}
}

void Board::turnAndPlayRandom()
{
	printBoard();
	srand(time(0));
	turn = true;
	while (true) {
		int row, col;
		if (turn) {
			cout << "Row and Col:: " << endl;
			cin >> row >> col;
			board[row][col] = player;
		}
		if (!turn) {
			do {
				row = rand() % 3;
				col = rand() % 3;
			} while (board[row][col] == player);
			board[row][col] = oponent;
		}
		turn = !turn;
		printBoard();
		if (checkVictory()) {
			if (!turn) {
				cout << "PLAYER WONN!!!" << endl;
				break;
			}
			if (turn) {
				cout << "OPONENT WONN!!!" << endl;
				break;
			}
		}
		if (isBoardFill()) {
			cout << "DRAWWW!!!!" << endl;
			break;
		}
	}
}

int Board::minMaxAlgo(int turn,int depth) {
	int score = checkVictory();
	if (score == 10) {
		return score - depth;
	}
	if (score == -10) {
		return score + depth;
	}
	if (isBoardFill()) {
		return 0;
	}
	if (turn) {
		int best = INT_MIN;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '_') {
					board[i][j] = oponent;
					best = std::max(best,minMaxAlgo(!turn, depth + 1));
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
	if (!turn) {
		int best = INT_MAX;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '_') {
					board[i][j] = player;
					best = std::min(best, minMaxAlgo(!turn, depth + 1));
					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}

void Board::findBestMove() {
	int bestVal = INT_MIN;
	int row, col;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '_') {
				board[i][j] = oponent;
				int movValue = minMaxAlgo(false, 0);
				board[i][j] = '_';
				if (movValue > bestVal) {
					bestVal = movValue;
					row = i;
					col = j;
				}
			}
		}
	}
	board[row][col] = oponent;
}

void Board::turnAndplayAI()
{
	printBoard();
	turn = true;
	while (true) {
		int row, col;
		if (turn) {
			cout << "Row and Col:: " << endl;
			cin >> row >> col;
			board[row][col] = player;
		}
		if (!turn) {
			findBestMove();
		}
		turn = !turn;
		printBoard();
		if (checkVictory()) {
			if (!turn) {
				cout << "PLAYER WONN!!!" << endl;
				break;
			}
			if (turn) {
				cout << "OPONENT WONN!!!" << endl;
				break;
			}
		}
		if (isBoardFill()) {
			cout << "DRAWWW!!!!" << endl;
			break;
		}
	}
}
