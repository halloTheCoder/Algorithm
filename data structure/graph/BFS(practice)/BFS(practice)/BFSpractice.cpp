// BFSpractice.cpp : Defines the entry point for the console application.
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
	g.addEdge(6, 0);   //TO TEST MOTHER VERTEX

	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4); //TO TEST ISTREE

	Graph g2(5);
	g2.addEdge(1, 0);
	g2.addEdge(0, 2);
	g2.addEdge(2, 1);
	g2.addEdge(0, 3);
	g2.addEdge(3, 4);  //TO TEST ISTREE

	std::cout << "Following is Breadth First Traversal " << std::endl;
	g.BFS();
	std::cout << "\nIs Tree : " << (g.getMotherVertex() != -1 ? g.getIsTree() : 0) << std::endl;
	std::cout << "Mother Vertex :: " << g.getMotherVertex() << std::endl;

	std::cout << "\nFollowing is Breadth First Traversal " << std::endl;
	g1.BFS();
	std::cout << "\nIs Tree : " << (g1.getMotherVertex() != -1 ? g1.getIsTree() : 0) << std::endl;
	std::cout << "Mother Vertex :: " << g1.getMotherVertex() << std::endl;

	std::cout << "\nFollowing is Breadth First Traversal " << std::endl;
	g2.BFS();
	std::cout << "\nIs Tree : " << (g2.getMotherVertex() != -1 ? g2.getIsTree() : 0) << std::endl;
	std::cout << "Mother Vertex :: " << g2.getMotherVertex() << std::endl;

	system("pause");
    return 0;
}

