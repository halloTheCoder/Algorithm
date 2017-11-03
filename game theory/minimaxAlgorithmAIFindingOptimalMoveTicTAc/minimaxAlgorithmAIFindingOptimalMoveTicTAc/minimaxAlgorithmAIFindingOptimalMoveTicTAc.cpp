//minimaxAlgorithmAIFindingOptimalMoveTicTAc.cpp : Defines the entry point for the console application.
//

//Let us combine what we have learnt so far about minimax and evaluation 
//function to write a proper Tic-Tac-Toe AI (Artificial Intelligence) that 
//plays a perfect game. This AI will consider all possible scenarios and makes the most optimal move.
//
//Finding the Best Move :
//
//We shall be introducing a new function called findBestMove().This function 
//evaluates all the available moves using minimax() and then returns the best move the maximizer can make.The pseudocode is as follows :
//
//function findBestMove(board) :
//	bestMove = NULL
//	for each move in board :
//		if current move is better than bestMove
//			bestMove = current move
//			return bestMove
//			Minimax :
//
//To check whether or not the current move is better than the best move we take 
//the help of minimax() function which will consider all the possible ways the game 
//can go and returns the best value for that move, assuming the opponent also plays optimally
//The code for the maximizer and minimizer in the minimax() function is similar to 
//findBestMove(), the only difference is, instead of returning a move, it will return a value.Here is the pseudocode :
//
//function minimax(board, depth, isMaximizingPlayer) :
//
//	if current board state is a terminal state :
//return value of the board
//
//if isMaximizingPlayer :
//	bestVal = -INFINITY
//	for each move in board :
//		value = minimax(board, depth + 1, false)
//		bestVal = max(bestVal, value)
//		return bestVal
//
//else :
//bestVal = +INFINITY
//for each move in board :
//	value = minimax(board, depth + 1, true)
//	bestVal = min(bestVal, value)
//	return bestVal
//
//	Checking for GameOver state :
//
//To check whether the game is over and to make sure there are no moves left 
//we use isMovesLeft() function.It is a simple straightforward function which 
//checks whether a move is available or not and returns true or false respectively.Pseudocode is as follows :
//
//function isMovesLeft(board) :
//	for each cell in board :
//		if current cell is empty :
//			return true
//return false

//http://www.geeksforgeeks.org/minimax-algorithm-in-game-theory-set-3-tic-tac-toe-ai-finding-optimal-move/

#include "stdafx.h"
#include "Board.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
	char board[3][3] =
	{
		{ 'x', '_', '_' },
		{ '_', '_', '_' },
		{ '_', '_', '_' }
	};

	Board b(board,3,3);

	b.printBoard();
	
	cout << endl;
	
	b.fillBoard();
	//b.findBestMove();
	
	/*cout << "The Optimal Move is :" << endl;
	cout << "ROW: " << b.row << "\nCOL: " << b.col << endl;*/

	cout << "Won :: " << b.won << endl;
	
	system("pause");
	return 0;
}

