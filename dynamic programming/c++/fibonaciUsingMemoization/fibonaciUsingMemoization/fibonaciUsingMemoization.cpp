// fibonaciUsingMemoization.cpp : Defines the entry point for the console application.

//FIBONACI :: MEMOIZATION -> TOP-BOTTOM

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <cstdio>

#define NIL INT_MIN
#define N 40

using namespace std;

int findFib(int n, vector<int> &store);

int main()
{
	vector<int> store(N + 1, NIL);
	
	clock_t begin, end;
	double time_spent;

	begin = clock();

	cout << findFib(N, store) << endl;

	end = clock();

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time Taken - %f\n", time_spent);

	system("pause");
    return 0;
}

int findFib(int n, vector<int> &store) {
	if (store[n] != NIL) {
		return store[n];
	}
	else {
		if (n <= 1) {
			store[n] = n;
		}
		else {
			store[n] = findFib(n - 1, store) + findFib(n - 2, store);
		}
		return store[n];
	}
}

