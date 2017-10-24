#include "stdafx.h"
#include "Graph.h"
#include "checkCycle.h"

#include <iostream>
#include <algorithm>

Graph::Graph(int v,int e)
{
	this->v = v;
	this->e = e;
	noOfEdge = 0;
	mst_wt = 0;
	cc = checkCycle(v);
}

void Graph::addEdge(int src, int dest, int weight)
{
	edges.push_back(std::make_pair(weight, std::make_pair(src, dest)));
}

void Graph::printEdges() {
	for (auto it = edges.begin(); it != edges.end(); it++) {
		std::cout << it->second.first << " - " << it->second.second << std::endl;
	}
	std::cout << std::endl;
}

void Graph::kruskalMST()
{
	while (noOfEdge != v - 1) {

		sort(edges.begin(), edges.end());

		int src = edges.begin()->second.first;
		int dest = edges.begin()->second.second;
		int wt = edges.begin()->first;

		cc.addEdge(src, dest);
		bool cycle = cc.hasCycle();
		//std::cout << std::boolalpha << cycle << std::endl;
		//cc.DFS();
		if (!cycle) {
			mst_wt += wt;
			std::cout << "(" << src << " - " << dest << ") :: " << wt << std::endl;
			//std::cout << mst_wt << " " << noOfEdge << std::endl;
			noOfEdge++;
		}
		else {
			cc.deleteEdge(src,dest);
		}
		edges.erase(edges.begin());
	}
}

