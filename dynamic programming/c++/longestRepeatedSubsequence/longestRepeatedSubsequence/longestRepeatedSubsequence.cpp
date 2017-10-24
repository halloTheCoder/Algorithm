// longestRepeatedSubsequence.cpp : Defines the entry point for the console application.

//NOTE::Contiguous Subarray Only

//Kadane’s Algorithm :
//
//Initialize:
//max_so_far = 0
//max_ending_here = 0
//
//Loop for each element of the array
//(a) max_ending_here = max_ending_here + a[i]
//(b) if (max_ending_here < 0)
//	max_ending_here = 0
//	(c) if (max_so_far < max_ending_here)
//	max_so_far = max_ending_here
//	return max_so_far

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int maxSubArraySum(int a[], int n, int &s, int &e);

int main()
{
	int a[] = { -2,-3,4,-1,-2,1,5,-3 };
	int n = sizeof(a) / sizeof(a[0]);
	int s, e;
	cout << maxSubArraySum(a, n,s,e) << endl;

	system("pause");
    return 0;
}

int maxSubArraySum(int a[], int n,int &s,int &e) {
	int max_ending_here = 0, max_so_far = INT_MIN;
	for (int i = 0; i < n; i++) {
		max_ending_here += a[i];

		if (max_ending_here > max_so_far) {
			max_so_far = max_ending_here;
			s = 
		}
		
		if (max_ending_here < 0) {
			max_ending_here = 0;
			s = i + 1;
		}
	}
	return max_so_far;
}
