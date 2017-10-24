#pragma once
#include <vector>
#include <climits>
#include <iostream>

class Graph
{
private:
	int v;
	std::vector<bool> mstSet;
	std::vector<int> child;
public:
	Graph(int v);
	void findMst(int graph[][5]);
	void printMst(int graph[][5]);
};

