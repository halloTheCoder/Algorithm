// ratMazeProblem.cpp : Defines the entry point for the console application.
//A Maze is given as N*N binary matrix of blocks where source block is the upper left most block 
//i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. 
//A rat starts from source and has to reach destination. The rat can move only in two directions: forward and down.
////In the maze matrix, 0 means the block is dead end and 1 means the block can be used in the path from 
//source to destination.Note that this is a simple version of the typical Maze problem.For example, a more 
//complex version can be that the rat can move in 4 directions and a more complex version can be with limited number of moves.

#include "stdafx.h"
#include "MazeRat.h"

#include <iostream>

// Maze size
#define N 4 

int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
	{ 1, 1, 0, 1 },
	{ 0, 1, 0, 0 },
	{ 1, 1, 1, 1 }
	};

	MazeRat rat(N);
	rat.solveMaze(maze);
	rat.printOuput();
	system("pause");
    return 0;
}

