// minCostPath.cpp : Defines the entry point for the console application.

//Given a cost matrix cost[][] and a position (m, n) in cost[][], 
//write a function that returns cost of minimum cost path to reach (m, n) from (0, 0).
//Each cell of the matrix represents a cost to traverse through that cell. 
//Total cost of a path to reach (m, n) is sum of all the costs on that 
//path (including both source and destination). 
//You can only traverse down, right and diagonally lower cells from a given cell, 
//i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) can be traversed. 
//You may assume that all costs are positive integers.
//
//http://www.geeksforgeeks.org/wp-content/uploads/dp.png
//
//The path with minimum cost is highlighted in the following figure.
//The path is(0, 0) –> (0, 1) –> (1, 2) –> (2, 2).The cost of the path is 8 (1 + 2 + 2 + 3).

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

#define R 3
#define C 3

using namespace std;

int minCost(int cost[][C], int m, int n);
int minCostUsingTabulation(int cost[][C], int i, int j, vector<vector<int> > costAtAPoint);

int main()
{
	int cost[R][C] = { { 1, 2, 3 },
	{ 4, 8, 2 },
	{ 1, 5, 3 } };
	
	vector<vector<int> > costAtAPath(R, vector<int>(C, 0));
	costAtAPath[0][0] = cost[0][0];

	cout << minCost(cost, 2, 2) << endl;

	cout << minCostUsingTabulation(cost, 2, 2, costAtAPath) << endl;

	system("pause");
    return 0;
}

int minCost(int cost[][C], int i, int j) {
	if (i == 0 && j == 0) {
		return cost[0][0];
	}
	if (i < 0 || j < 0)
		return INT_MAX;
	else {
		return cost[i][j] + min(minCost(cost, i - 1, j - 1), min(minCost(cost, i, j - 1), minCost(cost, i - 1, j)));
	}
}

int minCostUsingTabulation(int cost[][C], int m, int n,vector<vector<int> > costAtAPoint) {
	for (int i = 1; i <= n; i++) {
		costAtAPoint[0][i] = costAtAPoint[0][i - 1] + cost[0][i];
	}
	for (int i = 1; i <= m; i++) {
		costAtAPoint[i][0] = costAtAPoint[i - 1][0] + cost[i][0];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			costAtAPoint[i][j] = min(costAtAPoint[i - 1][j - 1], min(costAtAPoint[i - 1][j], costAtAPoint[i][j - 1])) + cost[i][j];
		}
	}
	return costAtAPoint[m][n];
}