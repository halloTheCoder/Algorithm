#include "stdafx.h"
#include "Tree.h"
#include "Node.h"

#include <iostream>
#include <algorithm>
#include <climits>

int maxDepth(Node *root) {
	if (root == nullptr)
		return 0;
	return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

void countNoOfNodes(Node *root,int &count) {
	if (root == nullptr)
		return;
	countNoOfNodes(root->left, count);
	count++;
	countNoOfNodes(root->right, count);
}

int _count(Node *root) {
	int c = 1;
	if (root == nullptr)
		return 0;
	c += _count(root->left);
	c += _count(root->right);
	return c;
}

int findMin(Node *root) {
	if (root == nullptr)
		return INT_MAX;
	if (root->value > std::min(findMin(root->left), findMin(root->right))) {
		return std::min(findMin(root->left), findMin(root->right));
	}
	else
		return root->value;
}

int findMax(Node *root) {
	if (root == nullptr)
		return INT_MIN;
	if (root->value < std::max(findMax(root->left), findMax(root->right))) {
		return std::max(findMax(root->left), findMax(root->right));
	}
	else
		return root->value;
}

int main()
{
	Node *root = new Node(6);
	root->left = new Node(10);
	root->right = new Node(9);
	root->left->left = new Node(100);
	root->left->right = new Node(3);

	std::cout << "Hight of tree is " << maxDepth(root) << std::endl;
	int count = 0;
	countNoOfNodes(root, count);
	std::cout << "Total no of nodes is " << count << std::endl;
	std::cout << "Total no of nodes is " << _count(root) << std::endl;
	std::cout << "min : "<< findMin(root) << "\nmax : " << findMax(root) <<std::endl;
	system("pause");
    return 0;
}


