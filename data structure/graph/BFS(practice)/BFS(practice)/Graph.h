#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class Graph
{
private:
	int v;
	std::vector<int> *adjL;
	bool isTree;
	int motherVertex;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	void BFS();
	bool getIsTree() { return isTree; }
	int getMotherVertex() { return motherVertex; }
};

