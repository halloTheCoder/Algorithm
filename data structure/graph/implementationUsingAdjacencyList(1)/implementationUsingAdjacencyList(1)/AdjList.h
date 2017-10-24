#pragma once
#include "Node.h"

class AdjList
{
private:
	Node **table;
	int v;
public:
	AdjList(int v);
	~AdjList();
	void addEdge(int src, int dest);
	void printAdjList();
};

