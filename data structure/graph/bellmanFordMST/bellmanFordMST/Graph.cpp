#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <climits>

Graph::Graph(int v,int e)
{
	this->v = v;
	this->e = e;
	distFromSrc = vector<int>(v, INT_MAX);
}

void Graph::addEdge(int src, int dest, int wt)
{
	edges.push_back(make_pair(wt, make_pair(src, dest)));
}

void Graph::bellmanFordSPT(int src)
{
	distFromSrc[src] = 0;                      //src is a source vertex
	for (int i = 1; i < v; i++) {
		int x = 1;
		for (int j = 0; j < e; j++) {
			int u = edges[j].second.first;
			int v = edges[j].second.second;
			int wt = edges[j].first;
			if (distFromSrc[u] != INT_MAX && distFromSrc[u] + wt < distFromSrc[v]) {
				x++;
				distFromSrc[v] = distFromSrc[u] + wt;
			}
		}
		if (x == 1)
			break;
	}
	// Step 3: check for negative-weight cycles.  The above step 
	// guarantees shortest distances if graph doesn't contain 
	// negative weight cycle.  If we get a shorter path, then there
	// is a cycle.
	for (int i = 0; i < e; i++)
	{
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		int wt = edges[i].first;
		if (distFromSrc[u] != INT_MAX && distFromSrc[u] + wt < distFromSrc[v])
			printf("Graph contains negative weight cycle");
	}

	printSPT();
}

void Graph::printSPT()
{
	std::cout << "VERTEX :: DISTFROMSRC" << std::endl;
	for (int i = 0; i < v; i++) {
		std::cout << i << "      ::      " << distFromSrc[i] << std::endl;
	}
}
