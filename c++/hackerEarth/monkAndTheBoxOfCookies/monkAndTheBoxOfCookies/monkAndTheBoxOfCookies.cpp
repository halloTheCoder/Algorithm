// monkAndTheBoxOfCookies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	//cout << "Hello World!" << endl;
	int t;
	sc(t);
	while (t--) {
		int n;
		sc(n);
		int *a = new int[n];
		forL(i, n) sc(a[i]);
		vector<int> count(32, 0);
		forL(i, n) {
			for (int j = 0; j<32; j++) {
				if (a[i] & (1 << j))
					count[j]++;
			}
		}
		cout << distance(count.begin(), max_element(count.begin(), count.end())) << endl;
	}
	return 0;
}


