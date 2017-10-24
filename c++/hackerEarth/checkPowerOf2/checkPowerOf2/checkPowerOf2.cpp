// checkPowerOf2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <bitset>

#define sc(n) cin>>n
#define forL(i,n) for(int i=0;i<n;i++)

std::string convertToBinary(unsigned int n);
int countSetBits(int n);

std::string str;

int main()
{
	using std::cin;
	unsigned int n;
	sc(n);
	std::string str = convertToBinary(n);
	std::cout << str << std::endl;
	if (countSetBits(n) == 1)
		std::cout << n << " power of 2." << std::endl;
	system("pause");
    return 0;
}

std::string convertToBinary(unsigned int n) {
	if (n / 2 == 0) {
		return (n % 2 ? "1" : "0");
	}
	str = convertToBinary(n / 2) + (n % 2 == 0 ? "0" : "1");
	return str;
}

int countSetBits(int n) {
	int count = 0;
	while (n) {
		n = n & n - 1;
		count++;
	}
	return count;
}