#pragma once
#include <vector>
#include <climits>
#include <iostream>

#define V 5

class Graph
{
private:
	int v;
	std::vector<bool> mstSet;
	std::vector<int> parent;
	std::vector<int> key;
public:
	Graph(int v);
	int minVertex();
	void primMST(int graph[][5]);
	void printMST(int graph[][5]);
};

