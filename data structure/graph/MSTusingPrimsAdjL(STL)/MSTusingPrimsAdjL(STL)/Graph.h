#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <climits>

using std::pair;
using std::vector;
using std::make_pair;

#define ip pair<int,int>

class Graph
{
private:
	int v;
	vector<ip> *adjL;
	vector<bool> mstSet;
	vector<int> parent, key;

public:
	Graph(int v);
	void addEdge(int src, int dest, int w);
	void printMST();
	void primMST();
};

