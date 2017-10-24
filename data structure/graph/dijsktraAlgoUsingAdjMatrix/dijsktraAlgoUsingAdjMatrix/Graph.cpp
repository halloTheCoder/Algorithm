#include "stdafx.h"
#include "Graph.h"

#include <climits>
#include <vector>
#include <iostream>

Graph::Graph(int v)
	:v(v)
{
	sptSet = std::vector<bool>(v, false);
	parent = std::vector<int>(v, -1);
	distFromSrc = std::vector<int>(v, INT_MAX);
	distFromSrc[0] = 0;
}

void Graph::dijkstra(int graph[][9], int src)
{
	dijkstraUtil(graph);
	printMST(graph);
}


void Graph::dijkstraUtil(int graph[][9])
{
	for (int count = 0; count < v - 1; count++) {
		int u = getMinWt();
		sptSet[u] = true;
		for (int j = 0; j < v; j++) {
			if (graph[u][j] && sptSet[j] == false && (distFromSrc[u] + graph[u][j]) < distFromSrc[j]) {
				parent[j] = u;
				distFromSrc[j] = graph[u][j] + distFromSrc[parent[j]];
			}
		}
	}
}

int Graph::getMinWt()
{
	int min = INT_MAX,min_index;
	for (int i = 0; i < v; i++) {
		if (!sptSet[i] && distFromSrc[i] < min) {
			min = distFromSrc[i];
			min_index = i;
		}
	}
	return min_index;
}

void Graph::printMST(int graph[][9])
{
	std::cout << "VERTEX :: DISTANCE_FROM_SRC" << std::endl;
	for (int i = 1; i < v; i++) {
		std::cout << i << " :: " << distFromSrc[i] << std::endl;
	}
}

