// dijsktraAlgoUsingAdjMatrix.cpp : Defines the entry point for the console application.

//Given a graph and a source vertex in graph, find shortest paths from source to all vertices in the given graph.

//Dijkstra’s algorithm is very similar to Prim’s algorithm for 
//minimum spanning tree.Like Prim’s MST, we generate a SPT(shortest path tree) 
//with given source as root.We maintain two sets, one set contains vertices 
//included in shortest path tree, other set includes vertices not yet included 
//in shortest path tree.At every step of the algorithm, we find a vertex which 
//is in the other set(set of not yet included) and has minimum distance from source.

//Algorithm::
//1) Create a set sptSet(shortest path tree set) that keeps track 
//of vertices included in shortest path tree, i.e., whose minimum 
//distance from source is calculated and finalized.Initially, this set is empty.
//
//2) Assign a distance value to all vertices in the input graph.
//Initialize all distance values as INFINITE.Assign distance value as 0 for the source vertex so that it is picked first.
//
//3) While sptSet doesn’t include all vertices
//….a) Pick a vertex u which is not there in sptSetand has minimum distance value.
//….b) Include u to sptSet.
//….c) Update distance value of all adjacent vertices of u.To update the distance 
//values, iterate through all adjacent vertices.For every adjacent vertex v, if 
//sum of distance value of u(from source) and weight of edge u - v, is less than 
//the distance value of v, then update the distance value of v.

//http://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg

#include "stdafx.h"
#include "Graph.h"

#include <iostream>

#define V 9

int main()
{
	//
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};

	Graph g(V);

	g.dijkstra(graph, 0);
	system("pause");
	return 0;
}

