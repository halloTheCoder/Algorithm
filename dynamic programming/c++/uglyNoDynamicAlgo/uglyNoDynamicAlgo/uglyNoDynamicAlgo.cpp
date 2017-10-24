// uglyNoDynamicAlgo.cpp : Defines the entry point for the console application.

//Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
//The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 
//11 ugly numbers. By convention, 1 is included.

//Here is a time efficient solution with O(n) extra space. The 
//ugly-number sequence is 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
//because every number can only be divided by 2, 3, 5, one way 
//to look at the sequence is to split the sequence to three groups as below :
//(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
//(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
//(3) 1×5, 2×5, 3×5, 4×5, 5×5, …

#include "stdafx.h"
#include <iostream>
#include <algorithm>

#define N 150

using namespace std;

int getNthUglyNo(int num, int ugly[]);

int main()
{
	int ugly[N + 1];
	ugly[0] = 0;

	cout << getNthUglyNo(N,ugly) << endl;

	system("pause");
    return 0;
}

int getNthUglyNo(int num,int ugly[]) {
	ugly[1] = 1;
	int count = 2, next_elem;
	int i2 = 1, i3 = 1, i5 = 1;
	int next_multiple_2 = 2, next_multiple_3 = 3, next_multiple_5 = 5;
	
	while (count < num) {
		next_elem = min(next_multiple_2, min(next_multiple_3, next_multiple_5));

		ugly[count] = next_elem;
		cout << "(" << ugly[count] << "," << count << ")" << " ";

		if (next_elem == next_multiple_2) {
			next_multiple_2 = ugly[++i2] * 2;
		}
		if (next_elem == next_multiple_3) {
			next_multiple_3 = ugly[++i3] * 3;
		}
		if (next_elem == next_multiple_5) {
			next_multiple_5 *= ugly[++i5] * 5;
		}
		count++;
	}
	
	return ugly[num];
}

