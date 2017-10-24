#pragma once
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class Graph
{
private:
	int v;
	stack<int> recurStack;
	vector<int> *adjL;
	vector<bool> visited;
	vector<int> indegree;
	void topologicalSortUtil(int i);
	void alltopologicalSortUtil(int i);

public:
	Graph(int v);
	void addEdge(int src, int dest);
	void topologicalSort();
	void alltopologicalSort();
};

