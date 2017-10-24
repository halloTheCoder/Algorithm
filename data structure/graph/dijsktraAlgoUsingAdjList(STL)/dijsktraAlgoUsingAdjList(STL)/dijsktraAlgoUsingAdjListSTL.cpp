// dijsktraAlgoUsingAdjListSTL.cpp : Defines the entry point for the console application.

//1) Initialize distances of all vertices as infinite.
//
//2) Create an empty priority_queue pq.Every item
//   of pq is a pair(weight, vertex).Weight(or
//	distance) is used used as first item  of pair
//	as first item is by default used to compare
//	two pairs
//
//	3) Insert source vertex into pq and make its
//	distance as 0.
//
//	4) While either pq doesn't become empty
//	a) Extract minimum distance vertex from pq.
//	Let the extracted vertex be u.
//	b) Loop through all adjacent of u and do
//	following for every vertex v.
//
//	// If there is a shorter path to v
//	// through u. 
//	If dist[v] > dist[u] + weight(u, v)
//
//	(i) Update distance of v, i.e., do
//	dist[v] = dist[u] + weight(u, v)
//	(ii) Insert v into the pq(Even if v is
//		already there)
//
//	5) Print distance array dist[] to print all shortest
//	paths.
//

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
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	g.shortestPath(0);

	system("pause");
    return 0;
}

