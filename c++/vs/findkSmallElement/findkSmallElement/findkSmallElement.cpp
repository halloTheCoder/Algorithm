// findkSmallElement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <vector>

#define sc(n) cin>>n;
#define forL(i,n) for(int i=0;i<n;i++)

using namespace std;

int select(int a[], int l, int r, int k);
int rand_partition(int a[], int l, int r, int mid);
int findMedian(int a[], int l, int r);

int step = 1;

int main()
{
	std::ios::sync_with_stdio(false);
	srand(time(0));
	int n;
	sc(n);
	int *a = new int[n];
	forL(i, n) sc(a[i]);
	int k;
	cout << "Enter k : " << endl;
	sc(k);
	cout<<select(a, 0, n - 1, k)<<endl;
	system("pause");
	return 0;
}

void bubbleSort(int a[], int l,int r)
{
	int i, j;
	for (i = l; i <= r; i++)

		// Last i elements are already in place   
		for (j = l; j < r - i; j += step)
			if (a[j] > a[j + step])
				swap(a[j], a[j + step]);
}

int findMedian(int a[], int l, int r) {
	if ((r-l) <= 20)
		return (r-l)/2;
	int i;
	for (i = l; (i + 4) <= r; i += 5) {
		bubbleSort(a + i, l , );
	}
	for (int k = l; k <= r; k++) cout << a[k] << " ";
	cout << endl;
	return findMedian(a,l+2,int(i-5/2-1));
}

int select(int a[], int l, int r, int k) {
	if (l == r)
		return a[l];
	int j = rand_partition(a,l,r,findMedian(a,l,r));
	int rank = j - l + 1;
	if (rank == k) {
		return a[j];
	}
	else if (rank > k)
		select(a, l, j - 1, k);
	else if (rank > k)
		select(a, j + 1, r, k - rank);
}

int rand_partition(int a[], int l, int r,int mid) {
	//int _rand = l + rand() % (r - l + 1);
	swap(a[mid],a[0]);
	int i = 1, j = r;
	int pivot = a[0];
	while (true) {
		while (i < r && a[i] < pivot)
			i++;
		while (j > 0 && a[j] > pivot)
			j--;
		if (i >= j)
			break;
		swap(a[i], a[j]);
	}
	swap(a[j], a[0]);
	return j;
}