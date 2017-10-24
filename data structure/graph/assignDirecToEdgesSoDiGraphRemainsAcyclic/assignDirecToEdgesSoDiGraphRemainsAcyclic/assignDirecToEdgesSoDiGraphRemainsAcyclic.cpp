// assignDirecToEdgesSoDiGraphRemainsAcyclic.cpp : Defines the entry point for the console application.

//Given a graph with both directed and undirected edges. It is given that the directed edges don’t form cycle. 
//How to assign directions to undirected edges so that the graph (with all directed edges) remains acyclic even after the assignment?

#include "stdafx.h"
#include "Graph.h"

#include <iostream>

int main()
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 5);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 4);
	g.addEdge(5, 2);
	
	std::vector<ip> undirEdges;
	undirEdges.push_back(std::make_pair(0, 2));
	undirEdges.push_back(std::make_pair(4, 5));
	undirEdges.push_back(std::make_pair(0, 3));
	
	g.assignDirection(undirEdges);
	g.DFS();

	system("pause");
    return 0;
}

