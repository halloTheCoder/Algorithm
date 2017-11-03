// bellmanFordSPT.cpp : Defines the entry point for the console application.

//Input: Graph and a source vertex src
//Output: Shortest distance to all vertices from src.
//	If there is a negative weight cycle, then shortest 
//	distances are not calculated, negative weight cycle is reported.

//How does this work ? Like other Dynamic Programming Problems, 
//the algorithm calculate shortest paths in bottom - up manner.
//It first calculates the shortest distances which have at - most 
//one edge in the path.Then, it calculates shortest paths with at - nost 2 edges, 
//and so on.After the i - th iteration of outer loop, the shortest paths with 
//at most i edges are calculated.There can be maximum | V | – 1 edges in any simple path, 
//that is why the outer loop runs | v | – 1 times.The idea is, assuming that there is no 
//negative weight cycle, if we have calculated shortest paths with at most i edges, then an
//iteration over all edges guarantees to give shortest path with at - most(i + 1) edges
//(Proof is simple, you can refer MIT Video Lecture -> http://www.youtube.com/watch?v=Ttezuzs39nk)

#include "stdafx.h"
#include "Graph.h"

#include <iostream>

int main()
{
	/* Let us create the graph given in above example */
	int V = 5;  // Number of vertices in graph
	int E = 8;  // Number of edges in graph
	
	Graph g(V, E);
	// add edge 0-1 (or A-B in above figure)
	g.addEdge(0, 1, -1);

	// add edge 0-2 (or A-C in above figure)
	g.addEdge(0, 2, 4);
	
	// add edge 1-2 (or B-C in above figure)
	g.addEdge(1, 2, 3);

	// add edge 1-3 (or B-D in above figure)
	g.addEdge(1, 3, 2);

	// add edge 1-4 (or A-E in above figure)
	g.addEdge(1, 4, 2);

	// add edge 3-2 (or D-C in above figure)
	g.addEdge(3, 2, 5);

	// add edge 3-1 (or D-B in above figure)
	g.addEdge(3, 1, 1);

	// add edge 4-3 (or E-D in above figure)
	g.addEdge(4, 3, -3);

	g.bellmanFordSPT(0);

	system("pause");
    return 0;
}

