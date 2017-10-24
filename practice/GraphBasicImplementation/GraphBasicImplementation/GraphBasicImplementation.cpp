// GraphBasicImplementation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

#include <iostream>

#define nL std::cout<<std::endl

int main()
{
	Graph g(7);
	g.addEdgeDi(0, 1);
	g.addEdgeDi(0, 5);
	g.addEdgeDi(0, 6);
	g.addEdgeDi(1, 2);
	g.addEdgeDi(1, 4);
	g.addEdgeDi(2, 6);
	g.addEdgeDi(3, 2);
	g.addEdgeDi(4, 3);
	g.addEdgeDi(5, 3);

	std::cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 3) \n";
	g.BFS(0);
	nL;
	
	std::cout << "Following is Depth First Traversal\n";
	g.DFS();
	nL;

	std::cout << std::boolalpha << g.detectCycleDi() << std::endl;
	
	if (!g.detectCycleDi()) {
		g.topologicalSort();
		nL;
	}

	g.findMotherVertex();
	std::cout << g.getMotherVertex() << std::endl;
	
	g.printTransClos();

	nL;

	//--------------------------------------------------------------------------------------------------------
	std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

	nL;

	Graph g1(7);
	g1.addEdgeUndi(0, 1);
	g1.addEdgeUndi(0, 5);
	g1.addEdgeUndi(0, 6);
	g1.addEdgeUndi(1, 2);
	g1.addEdgeUndi(1, 4);
	g1.addEdgeUndi(2, 6);
	g1.addEdgeUndi(3, 2);
	g1.addEdgeUndi(4, 3);
	g1.addEdgeUndi(5, 3);

	std::cout << std::boolalpha << g1.detectCycleUndi() << std::endl;

	Graph g4(7);
	g4.addEdgeUndi(0, 3);
	g4.addEdgeUndi(3, 2);
	g4.addEdgeUndi(2, 1);
	g4.addEdgeUndi(4, 2);
	g4.addEdgeUndi(5, 4);
	g4.addEdgeUndi(6, 5);
	//g4.addEdgeUndi(6, 0);
	if (g4.detectCycleUndi()) {
		std::cout << "Graph contains cycle and so it is not a tree\n";
	}
	else {
		std::cout << "Graph doesn't contain cycle\n";

		std::cout << std::boolalpha << g4.isTree << std::endl;
	}
	
	nL;

	//--------------------------------------------------------------------------------------------------------
	std::cout << "----------------------------------------------------------------------------------------------" << std::endl;

	nL;

	Graph gc(4);
	gc.addEdgeDi(0, 1);
	gc.addEdgeDi(0, 2);
	gc.addEdgeDi(1, 2);
	gc.addEdgeDi(2, 0);
	gc.addEdgeDi(2, 3);
	gc.addEdgeDi(3, 3);

	gc.findMotherVertex();
	std::cout << gc.getMotherVertex() << std::endl;

	gc.printTransClos();

	nL;

	system("pause");
    return 0;
}

