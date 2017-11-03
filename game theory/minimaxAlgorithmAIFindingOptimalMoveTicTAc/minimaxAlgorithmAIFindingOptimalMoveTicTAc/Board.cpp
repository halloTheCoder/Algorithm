#include "stdafx.h"
#include "Board.h"

#include <iostream>
#include <algorithm>
#include <climits>

Board::Board(char b[][3],int row,int col)
{
	move = false;
	won = 0;
	this->m = row;
	this->n = col;
	player = 'x';
	oponent = 'o';
	
	std::copy(b[0], b[0] + m*n, &this->board[0][0]);
	
	row = -1;
	col = -1;
}


bool Board::isMovesLeft()
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '_')
				return true;
		}
	}
	return false;
}

int Board::evaluate()
{
	for (int i = 0; i < m; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			if (board[i][0] == player)
				return +10;
			else if (board[i][0] == oponent)
				return -10;
		}
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			if (board[0][i] == player)
				return +10;
			else if (board[0][i] == oponent)
				return -10;
		}
	}
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
		if (board[1][1] == player)
			return +10;
		else if (board[1][1] == oponent)
			return -10;
	}
	return 0;
}

int Board::minimax(int depth, bool turn)
{
	int score = evaluate();

	// If Maximizer or Minimizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score - depth;
	if (score == -10)
		return score + depth;
	
	//NO more moves left and no one won
	if (!isMovesLeft())
		return 0;

	if (turn) {
		int bestValue = INT_MIN;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '_') {
					board[i][j] = player;
					bestValue = std::max(bestValue, minimax(depth + 1, !turn));
					board[i][j] = '_';
				}
			}
		}
		return bestValue;
	}
	else {
		int bestValue = INT_MAX;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '_') {
					board[i][j] = oponent;
					bestValue = std::min(bestValue, minimax(depth + 1, !turn));
					board[i][j] = '_';
				}
			}
		}
		return bestValue;
	}
	return 0;
}


void Board::findBestMove() {
	int bestVal = INT_MIN;
	int count = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '_') {
				if (count == 0) {
					row = i;
					col = j;
				}
				board[i][j] = player;
				int moveVal = minimax(0, false);
				
				if (moveVal > bestVal) {
					bestVal = moveVal;
					if(count > 0)
						board[row][col] = '_';
					row = i;
					col = j;
				}
				else {
					board[i][j] = '_';
				}
				count++;
			}
		}
	}
}

void print(char i) {
	std::cout << i << " ";
}

void Board::printBoard() {
	for (int i = 0; i < m; i++) {
		std::for_each(board[i], board[i] + n, print);
		std::cout << std::endl;
	}
}

void Board::fillBoard() {
	int score = evaluate();
	
	if (score > 0) {
		won = 1;
		return;
	}
	else if (score < 0) {
		won = -1;
		return;
	}
	
	if (move) {
		findBestMove();
		move = !move;
	}
	else {
		int x, y;
		std::cout << "Enter row and col :: " << std::endl;
		std::cin >> x >> y;
		board[x][y] = oponent;
		move = !move;
	}
	
	printBoard();
	std::cout << std::endl;
	
	fillBoard();
}