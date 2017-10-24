#include "stdafx.h"
#include "MazeRat.h"


MazeRat::MazeRat(int n)
{
	this->n = n;
	U = FixedUniverse(n*n);
}

void MazeRat::solveMaze(int maze[][4])
{
	constructMaze(maze);
	int i = 0, j = 0;
	path.push_back(make_pair(i, j));
	while (i != n-1 || j != n-1) {
		int x = U.getSuccessor1(i*n + j);
		int row = x / n;
		int col = x % n;
		while(!((row == i + 1 && col == j) || (row == i && col == j + 1))) {
			x = U.getSuccessor1(row*n + col);
			row = x / n;
			col = x % n;
		}
		path.push_back(make_pair(row, col));
		i = row;
		j = col;
	}
	//path.push_back(make_pair(n - 1, n - 1));
}

void MazeRat::constructMaze(int maze[][4])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j])
				U.insertElem(i*n + j);
		}
	}
}

void MazeRat::printOuput()
{
	std::cout << "PATH :: ";
	for (auto it = path.begin(); it != path.end(); it++) {
		std::cout << " -> (" << (*it).first << "," << (*it).second << ")";
	}
	std::cout << std::endl;
}


