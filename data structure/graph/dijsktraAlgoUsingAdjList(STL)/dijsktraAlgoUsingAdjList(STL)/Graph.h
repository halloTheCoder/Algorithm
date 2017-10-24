#pragma once
#include <vector>
#include <utility>

#define ipair std::pair<int,int>

class Graph
{
private:
	int v;
	std::vector<ipair> *adjL;
	std::vector<int> parent,distFromSrc;
	void printMST();

public:
	Graph(int v);
	void addEdge(int src, int dest, int wt);
	void shortestPath(int src);
};

