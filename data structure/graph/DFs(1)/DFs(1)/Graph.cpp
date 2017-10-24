#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	adjL = new vector<int>[v];
	visited = vector<bool>(v, false);
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
}

void Graph::DFS(int src)
{
	DFSUtil(src);
}

void Graph::DFSUtil(int i)
{
	visited[i] = true;
	cout << i << " ";

	for (auto it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (!visited[*it]) {
			DFSUtil(*it);
		}
	}
}

