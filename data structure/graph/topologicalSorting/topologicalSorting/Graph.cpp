#include "stdafx.h"
#include "Graph.h"

Graph::Graph(int v)
{
	this->v = v;
	adjL = new vector<int>[v];
	visited = vector<bool>(v, false);
	indegree = vector<int>(v, 0);
}

void Graph::addEdge(int src, int dest) {
	adjL[src].push_back(dest);
	indegree[dest]++;
}

void Graph::topologicalSort()
{
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			topologicalSortUtil(i);
		}
	}
	while (!recurStack.empty()) {
		std::cout << recurStack.top() << " ";
		recurStack.pop();
	}
	std::cout << std::endl;
}

void Graph::topologicalSortUtil(int i)
{
	visited[i] = true;
	for (vector<int>::iterator it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (!visited[*it]) {
			topologicalSortUtil(*it);
		}
	}
	recurStack.push(i);
}

void Graph::alltopologicalSortUtil(int i)
{
	visited[i] = true;
	
}

void Graph::alltopologicalSort()
{
	for (int i = 0; i < v; i++) {
		if (!visited[i])
			alltopologicalSortUtil(i);
	}
}

