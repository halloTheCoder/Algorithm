#pragma once
#include <vector>
#include <utility>

class Graph
{
private:
	int v;
	std::vector<std::pair<int, int> > *adjL;
	std::vector<int> parent,key;
	std::vector<bool> mstSet;

public:
	Graph(int v);
	void addEdge(int src, int dest, int wt);
	void primMST();
	void printMST();
};

