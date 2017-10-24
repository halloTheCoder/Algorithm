#pragma once
#include "checkCycle.h"

#include <vector>
#include <utility>

#define ipair std::pair<int,int>

class Graph
{
private:
	int v, e, noOfEdge;
	std::vector<int> parent;
	std::vector <std::pair<int, ipair> > edges;
	checkCycle cc;

public:
	int mstWt;
	Graph(int v,int e);
	void addEdge(int src, int dest, int wt);
	void kruskalMST();
};

