// quickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

#define forL(i,n) for(int i=0;i<n;i++)
#define sc(n) cin >> n

void quickSort(vector<int> &a, int l, int r);
int rand_partition(vector<int> &a, int l, int r);
int partition(vector<int> &a, int l, int r);
int find(vector<int> &a, int l, int r, int k);

int main()
{
	srand(time(unsigned(0)));
	int n;
	sc(n);
	
	vector<int> a(n);

	forL(i, n)
		sc(a[i]);
	
	vector<int> b = a;

	quickSort(a, 0, n - 1);

	for_each(a.begin(), a.end(), [&](int n) {
		cout << n << " ";
	});
	cout << endl;
	int k;
	sc(k);

	cout << find(b, 0, n - 1, k) << endl;

	system("pause");
	return 0;
}

int find(vector<int> &a, int l, int r, int k) {
	if (l >= r)
		return -1;
	int j = rand_partition(a, l, r);
	int rank = j - l + 1;
	if (rank == k)
		return a[j];
	else if (rank > k)
		return find(a, l, j - 1, k);
	else if (rank < k)
		return find(a, j + 1, r, k - rank);
}

void quickSort(vector<int> &a, int l, int r) {
	if (l < r) {
		int j = rand_partition(a, l, r);
		quickSort(a, l, j - 1);
		quickSort(a, j + 1, r);
	}
}

int rand_partition(vector<int> &a, int l, int r) {
	int random = l + rand() % (r - l + 1);
	swap(a[random], a[l]);
	int j = partition(a, l, r);
	return j;
}

int partition(vector<int> &a, int l, int r) {
	int i = l + 1, j = r;
	int pivot = a[l];
	while (1) {
		while (i <= r && a[i] <= pivot)
			i++;
		while (j > 0 && a[j] > pivot)
			j--;
		if (i > j)
			break;
		swap(a[i], a[j]);
		i++;
		j--;
	}
	swap(a[l], a[j]);
	return j;
}