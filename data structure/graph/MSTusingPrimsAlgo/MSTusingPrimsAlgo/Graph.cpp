#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	mstSet = std::vector<bool>(v, false);
	parent = std::vector<int>(v, 0);
	key = std::vector<int>(v, INT_MAX);
	key[0] = 0;
	parent[0] = -1;
}


int Graph::minVertex()             //finding minVertex w.r.t key(weight) values
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < v; i++) {
		if (mstSet[i] == false && key[v] < min) {
			min = key[v];
			min_index = i;
		}
	}
	return min_index;
}

void Graph::primMST(int graph[][5])
{
	for (int c = 0; c < v - 1; c++) {
		int u = minVertex();
		mstSet[u] = true;
		for (int i = 0; i < v; i++) {
			if (graph[u][i] && mstSet[i] == false && graph[u][i] < key[i]) {
				parent[i] = u;
				key[i] = graph[u][i];
			}
		}
	}
	printMST(graph);
}

void Graph::printMST(int graph[][5])
{
	std::cout << "WEIGHT   ::   EDGE" << std::endl;
	for (int i = 1; i < v; i++) {
		std::cout << graph[i][parent[i]] << " :: " << parent[i] << " - " << i << std::endl;
	}
}

