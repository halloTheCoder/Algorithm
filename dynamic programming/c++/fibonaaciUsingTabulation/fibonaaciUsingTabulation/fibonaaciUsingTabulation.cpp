// fibonaaciUsingTabulation.cpp : Defines the entry point for the console application.

//TABULATION :: BOTTOM-UP

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <cstdio>

#define NIL INT_MIN
#define N 40

using namespace std;

int findFib(int n, vector<int> &fib);

int main()
{
	vector<int> fib(N + 1, NIL);

	clock_t begin, end;
	double time_spent;

	begin = clock();
	cout << findFib(N, fib) << endl;
	end = clock();

	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

	printf("Time Taken - %lf \n", time_spent);

	system("pause");
    return 0;
}

int findFib(int n, vector<int> &fib) {
	fib[0] = 0;
	fib[1] = 1;
	int i = 2;
	while (i <= n) {             //@check
		fib[i] = fib[i - 1] + fib[i - 2];
		i++;
	}
	return fib[n];
}

