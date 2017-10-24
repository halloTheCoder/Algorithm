// randbuilttree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"

#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

int myrandom(int i) { return std::rand() % i; }

int main()
{
	std::srand(unsigned(time(0)));
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	int n;
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	Tree t;
	Node *root = nullptr;
	for(int i=0;i<n;i++)
		root = t.insertKey(root, a[i]);
	t.printLevelOrder(root);
	root = nullptr;
	std::shuffle(a, a + n, std::default_random_engine(seed));
	//or
	//std::random_shuffle(a, a + n, myrandom);
	for (int i = 0; i<n; i++)
		root = t.insertKey(root, a[i]);
	std::cout << std::endl;
	t.printLevelOrder(root);

	//implement quicksort with stable partition and print it like a tree

	system("pause");
    return 0;
}

