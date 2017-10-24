#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

class Graph
{
private:
	int v;
	std::vector<int> *adjL;
	int motherVertex;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	void DFS();
	void DFSUtility(int val, std::vector<bool> &visited);
	int getMotherVertex() { return motherVertex; }
};

