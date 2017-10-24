// detectCycleInUnDirGraph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"
#include <iostream>

int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	//g1.addEdge(2, 3);
	if (g1.isCyclic())
		cout << "Graph contains cycle\n";
	else
		cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	if (g2.isCyclic())
		cout << "Graph contains cycle\n";
	else
		cout << "Graph doesn't contain cycle\n";

	Graph g3(7);
	g3.addEdge(0, 1);
	g3.addEdge(0, 4);
	g3.addEdge(1, 2);
	g3.addEdge(1, 3);
	//g3.addEdge(1, 4);
	//g3.addEdge(4, 6);
	g3.addEdge(4, 5);
	g3.addEdge(5, 6);
	if (g3.isCyclic())
		cout << "Graph contains cycle\n";
	else
		cout << "Graph doesn't contain cycle\n";

	Graph g4(7);
	g4.addEdge(0, 3);
	g4.addEdge(3, 2);
	g4.addEdge(2, 1);
	g4.addEdge(4, 2);
	g4.addEdge(5, 4);
	g4.addEdge(6, 5);
	g4.addEdge(6, 0);
	if (g4.isCyclic())
		cout << "Graph contains cycle\n";
	else
		cout << "Graph doesn't contain cycle\n";
	
	system("pause");
    return 0;
}

