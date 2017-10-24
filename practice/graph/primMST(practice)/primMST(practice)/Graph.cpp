#include "stdafx.h"
#include "Graph.h"

#include <iostream>
#include <climits>
#include <queue>
#include <functional>

#define ipair std::pair<int,int>

Graph::Graph(int v)
{
	this->v = v;
	adjL = new std::vector<std::pair<int, int> >[v];
	mstSet = std::vector<bool>(v, false);
	parent = std::vector<int>(v, -1);
	key = std::vector<int>(v, INT_MAX);
	key[0] = 0;
}

void Graph::addEdge(int src, int dest, int wt)
{
	adjL[src].push_back(std::make_pair(dest, wt));
	adjL[dest].push_back(std::make_pair(src, wt));
}

void Graph::primMST() {
	int src = 0;
	std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair> > pq;
	pq.push(std::make_pair(0, src));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		mstSet[u] = true;
		for (auto &n : adjL[u]) {
			if (!mstSet[n.first] && n.second < key[n.first]) {
				parent[n.first] = u;
				key[n.first] = n.second;
				pq.push(std::make_pair(key[n.first],n.first));
			}
		}
	}
	printMST();
}

void Graph::printMST() {
	std::cout << "WEIGHT   ::    EDGES" << std::endl;
	for (int i = 1; i < v; i++) {
		std::cout << key[i] << "  ::  (" << parent[i] << ", " << i << ")" << std::endl;
	}
}
