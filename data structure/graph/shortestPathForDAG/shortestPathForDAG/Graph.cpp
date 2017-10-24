#include "stdafx.h"
#include "Graph.h"

#include <iostream>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<ipair>[v];
	visited = std::vector<bool>(v, false);
	distFromSrc = std::vector<int>(v, INT_MAX);
}

void Graph::topologicalUtil(int i)
{
	visited[i] = true;
	for (std::vector<ipair>::iterator it = adjL[i].begin(); it != adjL[i].end(); it++) {
		if (!visited[it->first]) {
			topologicalUtil(it->first);
		}
	}
	recurStack.push(i);
}

void Graph::addEdge(int src, int dest, int wt)
{
	adjL[src].push_back(std::make_pair(dest, wt));
}

void Graph::shortestPath(int src)
{
	distFromSrc[src] = 0;
	for (int i = 0; i < v; i++) {
		if(!visited[i])
			topologicalUtil(i);
	}
	while (!recurStack.empty()) {
		int u = recurStack.top();
		recurStack.pop();
		if (distFromSrc[u] != INT_MAX) {
			for (auto it = adjL[u].begin(); it != adjL[u].end(); it++) {
				if (distFromSrc[it->first] > distFromSrc[u] + it->second) {
					distFromSrc[it->first] = distFromSrc[u] + it->second;
				}
			}
		}
	}
	// Print the calculated shortest distances
	for (int i = 0; i < v; i++)
		(distFromSrc[i] == INT_MAX) ? std::cout << "INF " : std::cout << distFromSrc[i] << " ";
}
