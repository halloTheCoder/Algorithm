#include "stdafx.h"
#include "Graph.h"


Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<int>[v];
	//transMatrix = new std::vector<std::vector<int>>(v,std::vector<int>(v,0));
	transMatrix = new bool *[v];
	for (int i = 0; i < v; i++) {
		transMatrix[i] = new bool[v];
		for (int j = 0; j < v; j++) {
			transMatrix[i][j] = 0;
		}
	}
}

void Graph::addEdge(int src, int dest) {
	adjL[src].push_back(dest);
}

void Graph::DFS() {

	for (int i = 0; i < v; i++){ 
		DFSUtility(i,i);
	}
}

void Graph::DFSUtility(int val, int dest) {
	
	transMatrix[val][dest] = 1;

	for (auto it = adjL[dest].begin(); it != adjL[dest].end(); it++) {
		if (!transMatrix[val][*it]) {
			DFSUtility(val , *it);
		}
	}
}

void Graph::outputTransMatrix()
{
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++)
			std::cout << transMatrix[i][j] << " ";
		std::cout << std::endl;
	}
}

