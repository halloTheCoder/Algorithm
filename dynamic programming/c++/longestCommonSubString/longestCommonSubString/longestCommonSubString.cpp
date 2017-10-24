// longestCommonSubString.cpp : Defines the entry point for the console application.

//Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.

//Examples:
//
//Input: X = "GeeksforGeeks", y = "GeeksQuiz"
//	Output : 5
//	The longest common substring is "Geeks" and is of
//	length 5.
//
//	Input : X = "abcdxyz", y = "xyzabcd"
//	Output : 4
//	The longest common substring is "abcd" and is of
//	length 4.
//
//	Input : X = "zxabcdezy", y = "yzabcdezx"
//	Output : 6
//	The longest common substring is "abcdez" and is of
//	length 6.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int findLongestCommonSubstring(vector<char> x, vector<char> y, int row, int col, vector<vector<int> > &lookUp);

int main()
{
	string a = "abcdxyz", b = "xyzabcd";
	vector<char> x(a.begin(), a.end());
	vector<char> y(b.begin(), b.end());

	vector<vector<int> > lookUp(x.size() + 1, vector<int>(y.size() + 1, 0));
	
	cout << findLongestCommonSubstring(x, y, x.size(), y.size(), lookUp) << endl;

	system("pause");
    return 0;
}

int findLongestCommonSubstring(vector<char> x, vector<char> y, int row, int col, vector<vector<int> > &lookUp) {
	
	int len = 0, index_x = 0, index_y = 0;
	int i, j;
	
	for (i = 1; i <= row; i++) {
		
		for (j = 1; j <= col; j++) {
			
			if (x[i - 1] == y[j - 1]) {
				lookUp[i][j] = lookUp[i - 1][j - 1] + 1;
	
				if (len < lookUp[i][j]) {
					len = lookUp[i][j];
					index_x = i;
					index_y = j;
				}
			}

		}
	}
	
	char *LCS = new char[len + 1];
	LCS[len] = '\0';
	
	int index = len - 1;
	i = index_x; j = index_y;

	while (index >= 0) {
		LCS[index--] = y[--j];
		i--;
	}

	cout << LCS << endl;
	
	return len;
}
