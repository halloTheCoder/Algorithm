#pragma once
#include <cmath>
#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

class FixedUniverse
{
private:
	int sqrt_u;
	int **w;
	int *min, *max, *emp;
	void initialize();
	bool checkCase;
	int findSuccessor1(int a[], int low, int high);
	int findSuccessor2(int a[], int low, int high);
	int hasSuccessor(int a[], int low);

public:
	FixedUniverse(int u);
	void insertElem(int x);
	void deleteElem(int x);
	void printArray();
	int getSuccessor1(int x);
	int getSuccessor2(int x);

};

