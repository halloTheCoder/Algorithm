#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <climits>
#include <queue>
#include <functional>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<ipair>[v];
	parent = std::vector<int>(v, -1);
	distFromSrc = std::vector<int>(v, INT_MAX);
	distFromSrc[0] = 0;
}

void Graph::addEdge(int src, int dest, int wt)
{
	adjL[src].push_back(std::make_pair(dest, wt));
	adjL[dest].push_back(std::make_pair(src, wt));
}

void Graph::shortestPath(int src)
{
	std::priority_queue<ipair,std::vector<ipair>,std::greater<ipair> > pq;
	pq.push(std::make_pair(0, src));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (auto it = adjL[u].begin(); it != adjL[u].end(); it++) {
			int v = it->first;
			int wt = it->second;
			if (distFromSrc[u] + wt < distFromSrc[v]) {
				parent[u] = v;
				distFromSrc[v] = wt + distFromSrc[u];
				pq.push(std::make_pair(distFromSrc[v], v));
			}
		}
	}
	printMST();
}

void Graph::printMST()
{
	std::cout << "VERTEX :: DISTANCE_FROM_SRC" << std::endl;
	for (int i = 1; i < v; i++) {
		std::cout << i << " :: " << distFromSrc[i] << std::endl;
	}
}
