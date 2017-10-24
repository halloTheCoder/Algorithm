#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	adjL = new vector<int>[v];
	visited = vector<bool>(v, false);
	hasCycle = false;
}

void Graph::addEdge(int src, int dest)
{
	adjL[src].push_back(dest);
}

void Graph::BFS(int src)     //For simplicity, it is assumed that all vertices are reachable from the starting vertex.
{
	std::queue<int> qu;
	//std::set<int> s;
	qu.push(src);
	//s.insert(src);
	while (!qu.empty()) {
		int u = qu.front();
		if (visited[u]) {
			qu.pop();
			continue;
		}
		cout << u << " ";
		qu.pop();
		visited[u] = true;
		for (vector<int>::iterator it = adjL[u].begin(); it != adjL[u].end(); it++) {
			if (visited[*it])
				hasCycle = true;
			if (!visited[*it]) {
				qu.push(*it);
			}
		}
	}
}
