#pragma once

#include <vector>
#include <utility>

using std::vector;
using std::pair;
using std::make_pair;

#define ipair pair<int,int>

class Graph
{
private:
	int v, e;
	vector<pair<int, ipair> > edges;
	vector<int> distFromSrc;
public:
	Graph(int v,int e);
	void addEdge(int src, int dest, int wt);
	void bellmanFordSPT(int src);
	void printSPT();
};

