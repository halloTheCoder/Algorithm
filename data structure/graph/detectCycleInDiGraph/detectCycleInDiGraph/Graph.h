#pragma once
#include <vector>
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
class Graph
{
private:
	int v;
	vector<int> *adjL;
	vector<bool> visited, recurStack;
	bool hasCycle;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	bool isCyclic();
	void isCyclicUtil(int i);
};

