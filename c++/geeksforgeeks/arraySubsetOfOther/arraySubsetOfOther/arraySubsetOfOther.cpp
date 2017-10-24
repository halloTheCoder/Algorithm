// arraySubsetOfOther.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "arraySubsetOfOther.h"

#define sc(n) cin>>n
#define forL for(int i=0;i<n;i++)

bool checkSubset(int a1[], int a2[], int n, int m) {
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a1[i] < a2[j])
			i++;
		else if (a1[i] == a2[j]) {
			i++;
			j++;
		}
		else if (a1[i] > a2[j])
			return 0;
	}
	return j < m ? 0 : 1;
}

int main()
{
	using std::cin;
	int n, m;
	sc(n); sc(m);
	int *a1 = new int[n];
	for (int i = 0; i < n;i++)
		cin >> a1[i];
	int *a2 = new int[n];
	for (int i = 0; i < m;i++) 
		cin >> a2[i];
	std::stable_sort(a1, a1 + n);
	std::stable_sort(a2, a2 + m);
	std::cout << std::boolalpha << checkSubset(a1, a2, n, m) << std::endl;
	system("pause");
    return 0;
}

