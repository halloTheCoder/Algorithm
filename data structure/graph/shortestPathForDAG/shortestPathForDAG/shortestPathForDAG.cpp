// shortestPathForDAG.cpp : Defines the entry point for the console application.

//The idea is to use Topological Sorting.
//
//We initialize distances to all vertices as infinite and 
//distance to source as 0, then we find a topological sorting 
//of the graph.Topological Sorting of a graph represents a 
//linear ordering of the graph(See below, figure(b) is a linear 
//representation of figure(a)).Once we have topological 
//order(or linear representation), we one by one process 
//all vertices in topological order.For every vertex being 
//processed, we update distances of its adjacent using distance of current vertex.

//Following is complete algorithm for finding shortest distances.
//1) Initialize dist[] = { INF, INF, …. } and dist[s] = 0 where s is the source vertex.
//2) Create a toplogical order of all vertices.
//3) Do following for every vertex u in topological order.
//………..Do following for every adjacent vertex v of u
//………………if(dist[v] > dist[u] + weight(u, v))
//………………………dist[v] = dist[u] + weight(u, v)


#include "stdafx.h"
#include "Graph.h"

#include <iostream>

int main()
{
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);

	int s = 1;
	std::cout << "Following are shortest distances from source " << s << " \n";
	g.shortestPath(s);

	system("pause");
    return 0;
}

