#pragma once
#include <vector>
#include <climits>
#include <iostream>

using std::vector; 
using std::cout;
using std::endl;

class Graph
{
private:
	int v;
	vector<int> parent, key;
	vector<bool> mstSet;
public:
	Graph(int v);
	int minKey();
	void primMST(int graph[][5]);
	void printMST(int graph[][5]);
};

