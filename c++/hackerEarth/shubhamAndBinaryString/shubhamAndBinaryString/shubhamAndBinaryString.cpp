#include "stdafx.h"

#include <iostream>

#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, count = 0;
		cin >> n;
		char *ch = new char[n];
		cin >> ch;
		for (int i = 0; i<n; i++) {
			if (ch[i] == '0')
				count++;
		}
		cout << count << endl;
	}
	return 0;
}

