#include "stdafx.h"
#include "Graph.h"

void myfunc(int i) { std::cout << i << " "; }

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
	motherVertex = -1;
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
}

void Graph::DFS()
{
	std::vector<bool> visited(v, 0);
	for (int i = 0; i < v; i++) {
		if (!visited[i]) {
			DFSUtility(i, visited);
			//std::for_each(visited.begin(), visited.end(), myfunc);
			if (std::equal(visited.begin(), visited.end(), (new std::vector<bool>(v, 1))->begin())) {       //IMPORTANT
				motherVertex = i;
			}
			visited = std::vector<bool>(v, 0);
		}
	}
}

void Graph::DFSUtility(int val, std::vector<bool> &visited)
{
	visited[val] = 1;
	for (auto it = adjL[val].begin(); it != adjL[val].end(); it++) {
		if (!visited[*it]) {
			visited[*it] = 1;
			DFSUtility(*it, visited);
		}
	}
}


