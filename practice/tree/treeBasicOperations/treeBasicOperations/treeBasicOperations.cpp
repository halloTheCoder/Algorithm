// treeBasicOperations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include "Node.h"

#include <iostream>
#include <climits>
#include <algorithm>
#include <functional>
#include <numeric>

using std::cout;
using std::endl;


int main()
{
	Node *root = NULL;
	Tree t;
	root = t.insert_elem(root, 50);
	t.insert_elem(root, 30);
	t.insert_elem(root, 20);
	t.insert_elem(root, 40);
	t.insert_elem(root, 70);
	t.insert_elem(root, 60);
	t.insert_elem(root, 80);
	
	t.inOrder(root);
	cout << endl;

	t.printVerticalOrder(root);

	//cout << t.countNoOfNodes(root) << endl;
	cout << root->count << endl;

	Node *pre = nullptr, *succ = nullptr;
	int key = 60;

	t.findPreAndSucc(root, pre, succ, key);
	cout << "PRE :: " << (pre != NULL ? pre->item : INT_MAX) << " SUCC :: " << (succ != NULL ? succ->item : INT_MIN) << endl;

	std::vector<int> sumAll;
	int ll = 20, hl = 60;
	t.findAllWithinLimits(root, ll, hl, sumAll);

	std::for_each(sumAll.begin(), sumAll.end(), [&](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;

	std::cout << "sum :: " << std::accumulate(sumAll.begin(), sumAll.end(), 0, std::plus<int>()) << std::endl;

	Node *curr = t.kLargestElement(root, 5);
	cout << "K largest element :: " << curr->item << endl;

	//------------------------------------------------------------------------------------------------------------------------
	cout << "\n---------------------------------------------------------------------------------------------------------------\n" << endl;

	t.delete_elem(root,30);

	t.inOrder(root);
	cout << endl;

	t.printVerticalOrder(root);

	cout << t.countNoOfNodes(root) << endl;

	curr = t.kLargestElement(root, 5);
	cout << "K largest element :: " << curr->item << endl;

	system("pause");
    return 0;
}

