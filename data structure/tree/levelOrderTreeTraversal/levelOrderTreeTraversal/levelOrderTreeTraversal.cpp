// levelOrderTreeTraversal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <algorithm>

int findMaxDepth(Node *root) {
	if (root == nullptr)
		return 0;
	return std::max(findMaxDepth(root->left),findMaxDepth(root->right)) + 1;
}

void verticalOrder(Node *root, int i, int d) {
	if (root == nullptr)
		return;
	if (d == i) {
		std::cout << root->value << " ";
	}
	verticalOrder(root->left, i, d + 1);
	verticalOrder(root->right, i, d + 1);
}

void printLevelOrder(Node *root) {
	if (root == nullptr)
		return;
	int max = findMaxDepth(root);
	for (int i = 0; i < max; i++) {
		verticalOrder(root, i, 0);
		std::cout << std::endl;
	}
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->left->left->left = new Node(7);
	root->left->left->right = new Node(10);
	root->right->right = new Node(15);
	root->right->right->left = new Node(100);
	root->right->right->left->right = new Node(20);

	std::cout << "Level Order traversal of binary tree is " << std::endl;
	printLevelOrder(root);
	system("pause");
    return 0;
}

