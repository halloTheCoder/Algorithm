//O(n^2) method
//can do better 
//look for next one


#include "stdafx.h"
#include "Tree.h"
#include "Node.h"
#include <iostream>

Tree::Tree()
{
}

Node *Tree::insertKey(Node * root,int k)
{
	if (root == nullptr)
		return (new Node(k));
	if (root->value > k)
		root->left = insertKey(root->left, k);
	else if (root->value < k)
		root->right = insertKey(root->right, k);
	return root;
}

void Tree::findMinAndMax(Node * root, int *min, int *max, int r)
{
	if (root == nullptr)
		return;
	if (r < *min)
		*min = r;
	if (r > *max)
		*max = r;
	findMinAndMax(root->left, min, max, r - 1);
	findMinAndMax(root->right, min, max, r + 1);
}

void Tree::printVertical(Node * root,int lineNo, int r)
{
	if (root == nullptr)
		return;
	if (lineNo == r)
		std::cout << root->value << " ";
	
	printVertical(root->right, lineNo, r - 1);
	
	printVertical(root->left, lineNo, r + 1);
	
}

void Tree::orderVertical(Node * root)
{
	int min = 0, max = 0;
	findMinAndMax(root, &min, &max, 0);
	for (int i = min; i <= max; i++) {
		printVertical(root, i, 0);
		std::cout << std::endl;
	}
}

