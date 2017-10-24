#include "stdafx.h"
#include "FixedUniverse.h"


FixedUniverse::FixedUniverse()
{
}

FixedUniverse::FixedUniverse(int u)
{
	sqrt_u = int(std::sqrt(u));
	w = new int *[sqrt_u];
	for (int i = 0; i < sqrt_u; i++) {
		w[i] = new int[sqrt_u];
	}
	emp = new int[sqrt_u];
	min = new int[sqrt_u];
	max = new int[sqrt_u + 1];
	initialize();
}

void FixedUniverse::initialize()
{
	for (int i = 0; i < sqrt_u; i++) {
		emp[i] = min[i] = max[i] = 0;
		for (int j = 0; j < sqrt_u; j++) {
			w[i][j] = 0;
		}
	}
	max[sqrt_u] = 0;
}

void FixedUniverse::insertElem(int x)
{
	int high = x / sqrt_u, low = x % sqrt_u;
	int count = 0;
	w[high][low] = 1;
	emp[high] = 1;
	for (int i = 0; i < sqrt_u; i++) {
		if (w[high][i]) {
			if (count == 0) {
				min[high] = i;
			}
			count++;
			max[high] = i;
		}
		if (emp[i])
			max[sqrt_u] = i;
	}
}

void FixedUniverse::deleteElem(int x)
{
	int high = x / sqrt_u, low = x % sqrt_u;
	int count = 0;
	if(w[high][low])
		w[high][low] = 0;
	else {
		std::cout << "NOT PRESENT !!!!" << std::endl;
		return;
	}
	if (max[high] == min[high]) {
		emp[high] = 0;
		max[high] = min[high] = 0;
	}
	else {
		for (int i = 0; i < sqrt_u; i++) {
			if (w[high][i]) {
				if (count == 0) {
					min[high] = i;
				}
				count++;
				max[high] = i;
			}
		}
	}
}

int FixedUniverse::getSuccessor1(int x) {
	int high = x / sqrt_u, low = x % sqrt_u;
	checkCase = false;
	int succ = findSuccessor1(w[high], low, high);
	//cout << succ << checkCase << endl;
	if (checkCase)
		return succ;
	else
		return high*sqrt_u + succ;
}

int FixedUniverse::findSuccessor1(int a[],int low,int high)        //optimized T(u) = T(sqrt(u)) + O(1)
																   //T(u) = lg(lg(u))
{
	if (low < max[high]) {
		for (int i = low + 1; i < sqrt_u; i++) {
			if (a[i])
				return i;
		}
	}
	else {
		int i = findSuccessor1(emp,high,sqrt_u);
		checkCase = true;
		return i*sqrt_u + min[i];
	}
}

int FixedUniverse::getSuccessor2(int x) {              
	int high = x / sqrt_u, low = x % sqrt_u;
	checkCase = false;
	int succ = findSuccessor2(w[high], low, high);
	if (checkCase)
		return succ;
	else
		return high*sqrt_u + succ;
}

int FixedUniverse::findSuccessor2(int a[],int low,int high)                      //optimized T(u) = 3 * T(sqrt(u)) + O(1)
{
	if (hasSuccessor(a, low)) {
		return hasSuccessor(a, low);
	}
	else {
		int i = findSuccessor2(emp, high, sqrt_u);
		checkCase = true;
		return i*sqrt_u + findSuccessor2(w[i], -1, sqrt_u);
	}
}


int FixedUniverse::hasSuccessor(int a[], int low)
{
	for (int i = low + 1; i < sqrt_u; i++) {
		if (a[i])
			return i;
	}
	return 0;
}

void FixedUniverse::printArray()
{
	for (int i = 0; i < sqrt_u; i++) {
		for (int j = 0; j < sqrt_u; j++) {
			cout << w[i][j] << " ";
		}
		cout << endl;
	}
	//cout << endl;
}
