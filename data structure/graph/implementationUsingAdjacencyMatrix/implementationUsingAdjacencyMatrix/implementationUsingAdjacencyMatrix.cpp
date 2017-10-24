// implementationUsingAdjacencyMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void getaMatrix(int **a, int v) {
	for (int i = 0; i < v; i++)
	{
		for (int j = i; j < v; j++)
		{
			if (i != j)
			{
				std::cout << "Enter 1 if the vertex " << i + 1 << " is adjacent to " << j + 1 << ", otherwise 0: ";
				std::cin >> a[i][j];

				a[j][i] = a[i][j];
			}
			else
				a[i][j] = 0;
		}
	}
}

void printaMatrix(int **a, int v) {
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < v; j++)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}
}

int main()
{
	int vertex;
	std::cin >> vertex;
	int **aMatrix = new int *[vertex];
	for (int i = 0; i < vertex; i++)
		aMatrix[i] = new int[vertex];
	getaMatrix(aMatrix, vertex);
	printaMatrix(aMatrix, vertex);
	system("pause");
	return 0;
}

