// findSubsetsOfASet.cpp : Defines the entry point for the console application.

//Problem: Find all the subsets of a given set.
//
//Input:
//S = { a, b, c, d }
//Output:
//{}, { a }, { b }, { c }, { d }, { a,b }, { a,c },
//{ a,d }, { b,c }, { b,d }, { c,d }, { a,b,c },
//{ a,b,d }, { a,c,d }, { b,c,d }, { a,b,c,d }

#include "stdafx.h"
#include <iostream>
#include <array>
#include <cmath>
#include <vector>
#include <algorithm>

#define SIZE 3

void findAllSubsetsIterative(std::array<int, SIZE> set, int n);
void findSumOfAllSubsetsRecursively(std::array<int, SIZE> set, int l, int r, int sum);

std::vector<int> temp;

void print(int i) {
	std::cout << i << " ";
}

int main()
{
	std::array<int, SIZE> set = { 5,4,3 };
	
	findAllSubsetsIterative(set,set.size());
	
	std::cout << std::endl;

	findSumOfAllSubsetsRecursively(set, 0, set.size() - 1, 0);
	
	system("pause");
    return 0;
}

void findAllSubsetsIterative(std::array<int, SIZE> set, int n) {
	for (int i = 0; i < std::pow(2, n); i++) {                            //ITERATIVE APPROACH	
		int sum = 0;
		std::cout << "{ ";
		for (int j = 0; j < n; j++) {
			if (i & 1 << j) {                                        //seeing which bits are set in x
				std::cout << set[j] << " ";
				sum += set[j];
			}
		}
		std::cout << "}" << "  sum = " << sum << std::endl;
	}
}

void findSumOfAllSubsetsRecursively(std::array<int, SIZE> set, int l, int r, int sum) {
	if (l > r) {
		std::for_each(temp.begin(), temp.end(), print);
		std::cout << "  sum : " << sum << std::endl;
		return;
	}
	temp.push_back(set[l]);
	// Subset including arr[l]
	findSumOfAllSubsetsRecursively(set, l + 1, r, sum + set[l]);
	
	temp.erase(std::remove(temp.begin(), temp.end(), set[l]), temp.end());
	// Subset excluding arr[l]
	findSumOfAllSubsetsRecursively(set, l + 1, r, sum);
}