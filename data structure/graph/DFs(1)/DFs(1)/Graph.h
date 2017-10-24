#pragma once
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Graph
{
private:
	int v;
	vector<int> *adjL;
	vector<bool> visited;
public:
	Graph(int v);
	void addEdge(int src, int dest);
	void DFS(int src);
	void DFSUtil(int i);
};

