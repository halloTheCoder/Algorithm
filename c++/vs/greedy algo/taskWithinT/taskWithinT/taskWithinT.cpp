// taskWithinT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstdio>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n, t, currTime = 0, numOfThings = 0;
	sc(n);
	sc(t);
	int *a = new int[n];
	forL(i, n) sc(a[i]);
	sort(a, a + n);
	forL(i, n) {
		currTime += a[i];
		if (currTime > t)
			break;
		numOfThings++;
	}
	cout << numOfThings << endl;
	char ch;
	sc(ch);
    return 0;
}

