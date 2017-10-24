#pragma once
#include <iostream>
#include <vector>

class Graph
{
private:
	int v;
	std::vector<int> *adjL;
	//std::vector<std::vector<int>> *transMatrix;
	bool **transMatrix;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	void DFS();
	void DFSUtility(int val, int dest);
	void outputTransMatrix();
};

