#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
}

void Graph::DFS(int src)
{
	std::vector<bool> visited(v, 0);

	DFSutility(src, visited);

	std::cout << "\nFrOm AlL VerTicEs :: " << std::endl;
	
	visited = std::vector<bool>(v, 0);

	for (int i = 0; i < v; i++)
		if (visited[i] == false)
			DFSutility(i, visited);
	
}

void Graph::DFSutility(int src, std::vector<bool> &visited)
{
	visited[src] = 1;
	std::cout << src << " ";
	for (auto it = adjL[src].begin(); it != adjL[src].end(); it++) {
		if (!visited[*it]) {
			visited[*it] = 1;
			DFSutility(*it, visited);
		}
	}
}

