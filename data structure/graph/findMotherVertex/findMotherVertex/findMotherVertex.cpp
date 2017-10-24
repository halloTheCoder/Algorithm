// findMotherVertex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

#include <iostream>

int main()
{
	Graph g(7);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(4, 1);
	g.addEdge(6, 4);
	g.addEdge(5, 6);
	g.addEdge(5, 2);
	g.addEdge(6, 0);

	g.DFS();

	std::cout << "A mother vertex is " << g.getMotherVertex() << std::endl;
	system("pause");
    return 0;
}

