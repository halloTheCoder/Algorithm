#pragma once
#include <vector>
#include <utility>

#define ipair std::pair<int,int>

class Graph
{
private:
	int v;
	int wt;
	std::vector<ipair> *adjL;
	std::vector<bool> visitedPath;
	std::vector<int> path;
	void shortestPathUtil(int i,int dest);

public:
	Graph(int v);
	void addEdge(int src, int dest, int wt);
	int shortestPath(int src,int dest);
};

