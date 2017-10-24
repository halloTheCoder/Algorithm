#include "stdafx.h"
#include "Graph.h"
#include "checkCycle.h"

#include <iostream>
#include <algorithm>


using std::make_pair;

Graph::Graph(int v,int e)
{
	this->v = v;
	this->e = e;
	noOfEdge = 0;
	mstWt = 0;
	cc = checkCycle(v);
}

void Graph::addEdge(int src, int dest, int wt) {
	edges.push_back(make_pair(wt, make_pair(src, dest)));
}

void Graph::kruskalMST() {
	
	while (noOfEdge != v - 1) {
		sort(edges.begin(), edges.end());
		int u = edges.begin()->second.first;
		int v = edges.begin()->second.second;
		int wt = edges.begin()->first;
		cc.addEdge(u, v);
		if (!cc.detectCycle()) {
			mstWt += wt;
			std::cout << "(" << u << " - " << v << ") :: " << wt << std::endl;
			noOfEdge++;
		}
		else {
			cc.deleteEdge(u, v);
		}
		edges.erase(edges.begin());
	}
}