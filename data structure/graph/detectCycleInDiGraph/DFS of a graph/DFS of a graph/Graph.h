#pragma once

#include <vector>
#include <stack>
#include <iostream>

class Graph
{
private:
	int v;
	std::vector<int> *adjL;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	void DFS(int src);
	void DFSutility(int src, std::vector<bool> &visited);
};

