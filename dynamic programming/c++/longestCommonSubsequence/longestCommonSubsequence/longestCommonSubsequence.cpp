// longestCommonSubsequence.cpp : Defines the entry point for the console application.

//Example of dynamic programming

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int findLCS(vector<char> a, vector<char> b, int row, int col, vector<vector<int> > &C, string &LCS);

void print(int i) {
	cout << i << " ";
}

int main()
{
	string a ="ABCBDAB", b = "BDCABA";
	vector<char> x(a.begin(), a.end());
	vector<char> y(b.begin(),b.end());

	vector<vector<int> >C(y.size(), vector<int>(x.size(), 0));

	string LCS = "";
	
	cout << findLCS(x, y, y.size() - 1, x.size() - 1, C, LCS) << endl;

	for (int i = 0; i < y.size(); i++) {
		for_each(C[i].begin(), C[i].end(), print);
		cout << endl;
	}

	cout << LCS << endl;

	system("pause");
    return 0;
}

int findLCS(vector<char> x, vector<char> y, int row, int col, vector<vector<int> > &C, string &LCS) {
	int i = row, j = col;
	if (i == -1 || j == -1)
		return 0;
	if (C[i][j])
		return C[i][j];
	if (x[j] == y[i]) {
		C[i][j] = findLCS(x, y, row - 1, col - 1, C, LCS) + 1;
		if (LCS.size() < 4) {
			LCS += x[j];
		}
		return C[i][j];
	}
	else {
		C[i][j] = max(findLCS(x, y, row - 1, col, C, LCS), findLCS(x, y, row, col - 1, C, LCS));
		return C[i][j];
	}
}