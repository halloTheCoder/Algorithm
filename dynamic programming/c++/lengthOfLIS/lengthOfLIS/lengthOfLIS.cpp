// lengthOfLIS.cpp : Defines the entry point for the console application.

//The Longest Increasing Subsequence (LIS) problem is to find 
//the length of the longest subsequence of a given sequence 
//such that all elements of the subsequence are sorted in 
//increasing order. For example, 
//the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}

//Following is a tabluated implementation for the LIS problem.


#include "stdafx.h"
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define N 6

using namespace std;

int findLIS(array<int, N> a, int size, vector<int> store);

void print(int i) {
	cout << i << " ";
}

int main()
{
	array<int, N> a = { 10,22,9,33,21,50 };
	vector<int> store(a.size(), 1);          
	cout << findLIS(a, a.size(), store) << endl;
	
	system("pause");
    return 0;
}

int findLIS(array<int, N> a, int size, vector<int> store) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && store[i] < store[j] + 1) {
				store[i] = store[j] + 1;
			}
		}
	}
	for_each(store.begin(), store.end(), print);
	cout << endl;
	return *max_element(store.begin(), store.end());
}
