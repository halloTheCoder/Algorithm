#pragma once

#include <vector>

class Graph
{
private:
	int v;
	std::vector<int> *adj;
public:
	Graph(int v);
	void addEdge(int src, int des);
	void BFS(int s);     // prints BFS traversal from a given source s
};

