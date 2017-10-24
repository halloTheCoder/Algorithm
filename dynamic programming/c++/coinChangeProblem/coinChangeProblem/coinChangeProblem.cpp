// coinChangeProblem.cpp : Defines the entry point for the console application.

//TAKES ORDERED AS DIFFERENT i.e. (1,2,1) AND (2,1,1) AND (1,1,2) ARE DIFFERENT

/*Given 3 numbers{ 1, 3, 5 }, we need to tell
the total number of ways we can form a number 'N'
using the sum of the given three numbers.
(allowing repetitions and different arrangements).

Total number of ways to form 6 is : 8
1 + 1 + 1 + 1 + 1 + 1
1 + 1 + 1 + 3
1 + 1 + 3 + 1
1 + 3 + 1 + 1
3 + 1 + 1 + 1
3 + 3
1 + 5
5 + 1*/

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>

#define N 7
#define SIZE 3

using namespace std;

int findNoOfCoinChange(array<int, SIZE> coins, int n, vector<int> &lookUp);

int main()
{
	array<int, SIZE> coins = { 1, 3, 5 };
	vector<int> lookUp(N + 1, -1);

	cout << findNoOfCoinChange(coins, N, lookUp) << endl;
	
	system("pause");
    return 0;
}

int findNoOfCoinChange(array<int, SIZE> coins, int n, vector<int> &lookUp) {
	if (n < 0) {
		return 0;
	}
	if (n == 0)
		return 1;
	else {
		if (lookUp[n] != -1)
			return lookUp[n];
		int sum = 0;
		for (auto it = coins.begin(); it != coins.end(); it++) {
			sum += findNoOfCoinChange(coins, n - *it, lookUp);
		}
		lookUp[n] = sum;
		return sum;
	}
}