#pragma once
#include "FixedUniverse.h"
#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::make_pair;

#define ip pair<int,int>

class MazeRat : private FixedUniverse
{
private:
	int n;
	FixedUniverse U;
	vector<ip> path;
public:
	MazeRat(int n);
	void solveMaze(int maze[][4]);
	void constructMaze(int maze[][4]);
	void printOuput();
};

