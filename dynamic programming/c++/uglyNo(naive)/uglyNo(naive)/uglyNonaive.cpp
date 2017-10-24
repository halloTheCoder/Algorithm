// uglyNonaive.cpp : Defines the entry point for the console application.

//Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
//The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 
//11 ugly numbers. By convention, 1 is included.
//
//Given a number n, the task is to find n’th Ugly number.

#include "stdafx.h"
#include <iostream>
#include <cmath>

#define N 150

using namespace std;

int getNthUglyNo(int num);
bool isUgly(int n);
int maxDivide(int a, int b);

int main()
{
	cout << getNthUglyNo(N) << endl;

	system("pause");
	return 0;
}

int getNthUglyNo(int num) {
	int count = 0, ans = -1, i = 1;
	while (count < num) {
		if (isUgly(i)) {
			ans = i;
			//cout << ans << " ";
			count++;
		}
		i++;
	}
	return ans;
}

bool isUgly(int n) {
	n = maxDivide(n, 2);
	n = maxDivide(n, 3);
	n = maxDivide(n, 5);
	return n == 1 ? true : false;
}

int maxDivide(int a, int b) {
	while (a%b == 0) {
		a = a / b;
	}
	return a;
}