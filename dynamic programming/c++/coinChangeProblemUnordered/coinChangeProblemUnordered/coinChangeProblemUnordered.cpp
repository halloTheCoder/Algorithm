// coinChangeProblemUnordered.cpp : Defines the entry point for the console application.

//http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

//Given a value N, if we want to make change for N cents, 
//and we have infinite supply of each of S = { S1, S2, .. , Sm} 
//valued coins, how many ways can we make the change? The order of coins doesn’t matter.
//
//For example, for N = 4 and S = { 1,2,3 }, there are 
//four solutions : {1, 1, 1, 1}, { 1,1,2 }, { 2,2 }, { 1,3 }.
//So output should be 4. For N = 10 and S = { 2, 5, 3, 6 }, 
//there are five solutions : {2, 2, 2, 2, 2}, { 2,2,3,3 }, { 2,2,6 }, { 2,3,5 } and {5, 5}.
//So the output should be 5.

//see the downloaded video
//https://www.youtube.com/watch?v=k4y5Pr0YVhg

#include "stdafx.h"
#include <iostream>
#include <array>
#include <vector>

#define N 10
#define SIZE 4

using namespace std;

int findNoOfCoinChange(array<int, SIZE> coins, int n, int currentCoin, vector<int> &lookUp);

int main()
{
	array<int, SIZE> coins = { 2,5,3,6 };
	vector<int> lookUp(N + 1, -1);

	cout << findNoOfCoinChange(coins, N, 0, lookUp) << endl;
	
	system("pause");
    return 0;
}

int findNoOfCoinChange(array<int,SIZE> coins, int n, int currentCoin,vector<int> &lookUp) {
	// If n is less than 0 then no solution exists
	if (n < 0)
		return 0;
	// If n is 0 then there is 1 solution (do not include any coin)
	if (n == 0)                  
		return 1;
	else {
		if (lookUp[n] != -1)
			return lookUp[n];
		else {
			int sum = 0;
			for (int i = currentCoin; i < coins.size(); i++) {
				sum += findNoOfCoinChange(coins, n - coins[i], i, lookUp);
			}
			return sum;
		}
	}
}