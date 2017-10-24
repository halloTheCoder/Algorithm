// pathMoreThanKlengthFromSrc.cpp : Defines the entry point for the console application.

//Given a graph, a source vertex in the graph and a number k, 
//find if there is a simple path (without any cycle) starting from 
//given source and ending at any other vertex.

//http://www.geeksforgeeks.org//wp-content/uploads/Fig-11.jpg

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

	int src = 0;
	int k = 62;
	g.pathMoreThanK(src, k) ? std::cout << "Yes\n" :
		std::cout << "No\n";

	k = 60;
	g.pathMoreThanK(src, k) ? std::cout << "Yes\n" :
		std::cout << "No\n";
	std::cout << "Max Wt Path :: " << g.getMaxWtPath() << std::endl;
	system("pause");
    return 0;
}

