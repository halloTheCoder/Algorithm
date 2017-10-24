// taskWithinTwithPriority.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdio>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int n;
	sc(n);
	int *p = new int[n];
	int *t = new int[n];
	forL(i, n) sc(p[i]);
	forL(i, n) sc(t[i]);
	vector<pair<double, int>> vec;
	forL(i, n) {
		vec.push_back(make_pair(p[i] / t[i], i));
	}
	sort(vec.begin(), vec.end());
	int c = 0, f = 0;
	forL(i, n) {
		c += t[vec[i].second];
		f += p[vec[i].second] * c;
	}
	cout << f << endl;
	system("pause");
    return 0;
}

