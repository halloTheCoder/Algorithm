// checkSkewedTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"

#include <iostream>
#include <climits>

#define nl std::cout<<std::endl

bool checkSkewedTree(Node *root, int ll, int hl) {
	if (root == nullptr)
		return true;
	if (root->right != nullptr && root->left != nullptr)
		return false;
	else {
		if (root->value <= ll || root->value >= hl)
			return false;
		else {
			if (root->right == nullptr) {
				hl = root->value;
				checkSkewedTree(root->left, ll, hl);
			}
			else {
				ll = root->value;
				checkSkewedTree(root->right, ll, hl);
			}
		}
	}
}

int main()
{
	Tree t;
	Node *root = NULL;
	root = t.insertKey(root, 50);
	t.insertKey(root, 30);
	t.insertKey(root, 20);
	t.insertKey(root, 40);
	t.insertKey(root, 70);
	t.insertKey(root, 60);
	t.insertKey(root, 80);

	t.inorderDepthTraversal(root);
	nl;
	t.inorderBreadthTraversal(root);
	
	int ll = INT_MIN, hl = INT_MAX;
	nl;
	std::cout << std::boolalpha << checkSkewedTree(root, ll, hl) << std::endl;
	
	root = NULL;
	root = t.insertKey(root, 70);
	t.insertKey(root, 30);
	t.insertKey(root, 40);
	t.insertKey(root, 50);
	t.insertKey(root, 60);
	t.insertKey(root, 55);
	t.insertKey(root, 58);
	nl;
	t.inorderBreadthTraversal(root);
	nl;
	t.inorderDepthTraversal(root);
	nl;
	std::cout << std::boolalpha << checkSkewedTree(root, ll, hl) << std::endl;

	system("pause");
    return 0;
}

