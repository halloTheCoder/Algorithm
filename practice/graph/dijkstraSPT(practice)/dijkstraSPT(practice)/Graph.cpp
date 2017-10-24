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
	sptSet = std::vector<bool>(v, false);
	distFromSrc[0] = 0;
}

void Graph::addEdge(int src, int dest, int wt) {
	adjL[src].push_back(std::make_pair(dest, wt));
	adjL[dest].push_back(std::make_pair(src,wt));
}

void Graph::shortestPath(int src) {
	std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair> > pq;
	pq.push(std::make_pair(0,src));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		sptSet[u] = true;
		for (auto &n : adjL[u]) {
			if (!sptSet[n.first] && distFromSrc[u] + n.second < distFromSrc[n.first]) {
				distFromSrc[n.first] = distFromSrc[u] + n.second;
				pq.push(std::make_pair(distFromSrc[n.first],n.first));
				parent[n.first] = u;
			}
		}
	}
	printSPT();
}

void Graph::printSPT() {
	std::cout << "DISTFROMSRC :: PATH" << std::endl;
	for (int i = 1; i < v; i++) {
		std::cout << distFromSrc[i] << " ::  0";
		outputPath(i);
		std::cout << std::endl;
	}
}

void Graph::outputPath(int i) {
	if (i == 0)
		return;
	outputPath(parent[i]);
	std::cout << " -> " << i;
}