#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using std::vector;
using std::cout;
using std::endl;

class Graph
{
private:
	int v;
	vector<int> *adjL;
	vector<bool> visited;
	bool hasCycle;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	void BFS(int src);
	int getCycle() const { return hasCycle; }
};

