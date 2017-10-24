// findSuccessor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include "Node.h"

#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
#include <algorithm>

int countNoOfNodes(Node *root) {
	int c = 1;
	if (root == nullptr)
		return 0;
	c += countNoOfNodes(root->left) + countNoOfNodes(root->right);
	return c;
}

void findPreSuc(Node *root, Node * &pre, Node * &suc,int key){           //IMPORTANT
	if (root == nullptr)
		return;
	if (root->value == key) {
		findPreAndSucc(root->left, pre, suc, key);
		findPreAndSucc(root->right, pre, suc, key);
	}
	if (root->value > key) {
		suc = root;
		findPreSuc(root->left, pre, suc, key);
	}
	else if(root->value < key){
		pre = root;
		findPreSuc(root->right, pre, suc, key);
	}
}

void findSuccUsingLoop(Node *root,int key,Node *&suc) {
	if (root == nullptr)
		return;
	suc = root;
	Node *x = root;
	while (x != nullptr && x->value != key) {
		if (x->value > key) {
			 suc = x;
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	if (x->right != nullptr) {
		x = x->right;
		while (x->left != nullptr)
			x = x->left;
		suc = x;
	}
}

void findAllWithinLimits(Node *root, int &ll, int &hl, std::vector<int> &sumAll) {
	if (root == nullptr)
		return;
	if (root->value < ll)
		findAllWithinLimits(root->right, ll, hl, sumAll);
	
	if (root->value >= ll && root->value <= hl) {
		sumAll.push_back(root->value);
		findAllWithinLimits(root->left, ll, hl, sumAll);
		findAllWithinLimits(root->right, ll, hl, sumAll);
	}

	else if (root->value > hl)
		findAllWithinLimits(root->left, ll, hl, sumAll);
}

int main()
{
	int key = 60;
	Tree t;
	Node *root = NULL;
	root = t.insertKey(root, 55);
	t.insertKey(root, 30);
	t.insertKey(root, 20);
	t.insertKey(root, 40);
	t.insertKey(root, 70);
	t.insertKey(root, 60);
	t.insertKey(root, 80);
	Node *pre = nullptr, *suc = nullptr;
	findPreSuc(root,pre,suc,key);
	std::cout << key <<" key has\nPredessor : " << pre->value << "\nSuccessor : " << suc->value << std::endl;
	suc = nullptr;
	findSuccUsingLoop(root, key, suc);
	std::cout << key << " key has\nSuccessor : " << suc->value << std::endl;
	
	std::cout << "Count :: " << countNoOfNodes(root) << std::endl;
	
	std::vector<int> sumAll;
	int ll = 20, hl = 70;
	findAllWithinLimits(root, ll, hl,sumAll);

	std::for_each(sumAll.begin(), sumAll.end(), [&](int n) {
		std::cout << n << " ";
	});
	std::cout << std::endl;

	std::cout << "sum :: " << std::accumulate(sumAll.begin(), sumAll.end(), 0, std::plus<int>()) << std::endl;
	
	system("pause");
    return 0;
}

