#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	mstSet = std::vector<bool>(v, false);
	child = std::vector<int>(v, -1);
}

void Graph::findMst(int graph[][5])
{
	for (int i = 0; i < v; i++) {
		mstSet[i] = true;
		int min = INT_MAX;
		for (int j = 0; j < v; j++) {
			if (graph[i][j] && i != child[j] && graph[i][j] < min) {
				min = graph[i][j];
				child[i] = j;
			}
		}
	}
	printMst(graph);
}

void Graph::printMst(int graph[][5])
{
	std::cout << "EDGE  ::  WEIGHT" << std::endl;
	for (int i = 0; i < v; i++) {
		std::cout << i << " - " << child[i] << " :: " << graph[i][child[i]] << std::endl;
	}
}


