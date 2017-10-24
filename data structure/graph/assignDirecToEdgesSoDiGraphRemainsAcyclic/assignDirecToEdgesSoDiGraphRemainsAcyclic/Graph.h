#pragma once

#include <vector>
#include <utility>
#include <stack>

#define ip std::pair<int,int>

class Graph
{
private:
	int v;
	std::vector<int> *adjL;
	std::vector<bool> visited;
	std::stack<int> recurStack;
	std::vector<int> stack;
	void assignDirectionUtil(int i);
	void DFSUtil(int i);
public:
	Graph(int v);
	void addEdge(int src, int dest);
	void assignDirection(std::vector<ip> &undirEdges);
	void DFS();
};

