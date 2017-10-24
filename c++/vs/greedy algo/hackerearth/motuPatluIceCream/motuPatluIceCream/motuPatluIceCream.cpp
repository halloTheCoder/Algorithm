// motuPatluIceCream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int main()
{
	int t;
	sc(t);
	while (t--) {
		int win = 0,n;
		int count = 0;
		sc(n);
		int *a = new int[n];
		forL(i, n) sc(a[i]);
		int i = 0, j = n - 1;
		int c_motu = 0, c_patlu = 0;
		while (true) {
			if (a[i] > (a[j] * 2)) {
				if (count == 0)
					c_motu++;
				a[i] -= a[j] * 2;
				c_patlu++;
				count++;
				j--;
				if (i == j) {
					win = -1;
					break;
				}
			}
			else if (a[i] < (a[j] * 2)) {
				if (count == 0)
					c_patlu++;
				a[j] -= (a[i] / 2);
				c_motu++;
				count++;
				i++;
				if (i == j) {
					win = 1;
					break;
				}
			}
			else if (a[i] == (a[j] * 2)) {
				i++;
				count++;
				if (i == j) {
					win = 0;
					c_motu++;
					c_patlu++;
					break;
				}
				j--;
				c_motu++;
				c_patlu++;
			}
		}
		cout << c_motu << " " << c_patlu  << endl;
		cout << (win == 1 ? "Motu" : (win == -1 ? "Patlu" : "Tie")) << endl;
	}
	system("pause");
	return 0;
}


