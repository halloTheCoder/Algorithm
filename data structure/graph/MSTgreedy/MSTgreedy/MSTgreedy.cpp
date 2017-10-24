// MSTgreedy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"

#define V 5

int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
	{ 2, 0, 3, 8, 5 },
	{ 0, 3, 0, 0, 7 },
	{ 6, 8, 0, 0, 9 },
	{ 0, 5, 7, 9, 0 },
	};

	// Print the solution
	Graph g(V);
	g.findMst(graph);
	system("pause");
	return 0;
}

