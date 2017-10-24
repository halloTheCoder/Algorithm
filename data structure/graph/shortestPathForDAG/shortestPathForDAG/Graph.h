#pragma once
#include <vector>
#include <utility>
#include <stack>
#include <climits>

#define ipair std::pair<int,int>

class Graph
{
private:
	int v;
	std::vector<ipair> *adjL;
	std::vector<int> distFromSrc;
	std::vector<bool> visited;
	std::stack<int> recurStack;
	void topologicalUtil(int i);

public:
	Graph(int v);
	void addEdge(int src, int dest, int wt);
	void shortestPath(int src);
};

