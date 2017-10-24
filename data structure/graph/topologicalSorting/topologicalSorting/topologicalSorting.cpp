// topologicalSorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

#include <iostream>

int main()        //Topological Sorting for DAG(Directed Acyclic Graph)
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	std::cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();

	system("pause");
    return 0;
}

