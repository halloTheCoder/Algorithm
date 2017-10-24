#pragma once
#include "checkCycle.h"
#include <vector>
#include <utility>

#define ip std::pair<int,int>

class Graph
{
private:
	int v,e,noOfEdge,mst_wt;
	checkCycle cc;
	std::vector<std::pair<int, ip> > edges;
public:
	Graph(int v,int e);
	void addEdge(int src, int dest, int weight);
	void kruskalMST();
	int getMSTwt() { return mst_wt; }
	void printEdges();
};

