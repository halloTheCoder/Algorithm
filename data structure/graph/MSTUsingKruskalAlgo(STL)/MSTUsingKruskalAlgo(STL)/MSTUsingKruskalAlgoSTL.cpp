// MSTUsingKruskalAlgoSTL.cpp : Defines the entry point for the console application.

//Greedy Algorithm -> Kruskal’s Minimum Spanning Tree Algorithm
//
//1. Sort all the edges in non-decreasing order of their weight.
//2. Pick the smallest edge.Check if it forms a cycle with the spanning tree
//formed so far.If cycle is not formed, include this edge.Else, discard it.
//
//3. Repeat step#2 until there are(V - 1) edges in the spanning tree.

#include "stdafx.h"
#include "Graph.h"

#include <iostream>

int main()
{
	int V = 9, E = 14;
	Graph g(V, E);

	//  making above shown graph
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	std::cout << "Edges of MST are \n";
	g.kruskalMST();

	std::cout << "\nWeight of MST is " << g.getMSTwt() << std::endl;
	
	system("pause");
    return 0;
}

