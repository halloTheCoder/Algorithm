#pragma once

#include <vector>

class Graph
{
private:
	int v;
	std::vector<bool> sptSet;
	std::vector<int> parent, distFromSrc;
	void dijkstraUtil(int graph[][9]);
	int getMinWt();
	void printMST(int graph[][9]);
public:
	Graph(int v);
	void dijkstra(int graph[][9], int src);
};

