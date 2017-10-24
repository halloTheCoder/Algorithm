// DFs1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal (starting from vertex 2) \n";
	g.DFS(2);

	system("pause");
	return 0;
}

