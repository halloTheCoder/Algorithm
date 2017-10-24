// shoretestPath.cpp : Defines the entry point for the console application.

//outputing shortest path by checking every direction from src to dest.

#include "stdafx.h"
#include "Graph.h"
#include <iostream>

int main()
{
	// create the graph given in above fugure
	int V = 9;
	Graph g(V);

	//  making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 5, 4);
	g.addEdge(2, 8, 2);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);
	
	for (int i = 1; i < V; i++) {
		std::cout << "0 - " << i << " :: " << g.shortestPath(0, i) << std::endl;
	}

	//std::cout << g.shortestPath(0, 7) << std::endl;

	system("pause");
    return 0;
}

