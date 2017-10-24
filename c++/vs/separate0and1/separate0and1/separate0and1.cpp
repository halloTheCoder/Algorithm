// separate0and1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

#define sc(n) cin>>n;
#define forL(i,n) for(int i=0;i<n;i++)

int main()
{
	using std::cout;
	using std::cin;
	using std::swap;
	int n;
	sc(n);
	int *a = new int[n];
	forL(i, n) sc(a[i]);
	int i = 0, j = n - 1;
	while (true) {
		while (i < n - 1 && a[i] == 0)
			i++;
		while (j > 0 && a[j] == 1)
			j--;
		if (i >= j)
			break;
		swap(a[i], a[j]);
	}
	forL(i, n) cout << a[i] << " ";
	system("pause");
    return 0;
}

