// longestLCS.cpp : Defines the entry point for the console application.

//LCS -> example of dyanamic programming

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void findLCS(vector<char> x, vector<char> y, int row, int col, vector<vector<int> > &C);

void print(int i) {
	cout << i << " ";
}

int main()
{
	string a = "ABCBDAB", b = "BDCABA";
	
	vector<char> x(a.begin(), a.end());
	vector<char> y(b.begin(), b.end());

	vector<vector<int> > C(b.size() + 1, vector<int>(a.size() + 1, 0));

	findLCS(x, y, y.size(), x.size(), C);

	system("pause");
    return 0;
}

void findLCS(vector<char> x, vector<char> y, int row, int col, vector<vector<int> > &C) {
	for (int i = 0; i <= row; i++) {
		for (int j = 0; j <= col; j++) {
			if (i == 0 || j == 0) {
				C[i][j] = 0;
			}
			else {
				if (x[j - 1] == y[i - 1]) {
					C[i][j] = C[i - 1][j - 1] + 1;
				}
				else {
					C[i][j] = max(C[i - 1][j], C[i][j - 1]);
				}
			}
		}
	}

	for (int i = 0; i <= row; i++) {
		for_each(C[i].begin(), C[i].end(), print);
		cout << endl;
	}

	int len = C[row][col];
	char *LCS = new char[len + 1];      //+1 for NULL character
	LCS[len] = '\0';
	int index = len - 1;
	
	int i = row, j = col;
	while (i > 0 && j > 0) {
		if (x[j - 1] == y[i - 1]) {
			LCS[index--] = x[j - 1];
			i--; j--;
		}
		else {
			if (C[i - 1][j] >= C[i][j - 1]) {                  //ouput :: "BCBA" if change from '>=' to '>' then output "BDAB"
				i--;
			}
			else {
				j--;
			}
		}
	}
	cout << LCS << endl;
}