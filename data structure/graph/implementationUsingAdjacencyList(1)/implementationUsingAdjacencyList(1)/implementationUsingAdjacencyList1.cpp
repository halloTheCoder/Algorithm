// implementationUsingAdjacencyList1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AdjList.h"
#include "Node.h"

#include <iostream>

int main()
{
	AdjList aList(5);
	aList.addEdge(0, 1);
	aList.addEdge(0, 4);
	aList.addEdge(1, 2);
	aList.addEdge(1, 3);
	aList.addEdge(1, 4);
	aList.addEdge(2, 3);
	aList.addEdge(3, 4);
	aList.printAdjList();
	system("pause");
	return 0;
}

