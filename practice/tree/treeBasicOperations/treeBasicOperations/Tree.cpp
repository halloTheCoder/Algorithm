#include "stdafx.h"
#include "Tree.h"

#include <iostream>


Tree::Tree()
{
}


void Tree::inOrder(Node * root)
{
	if (root == NULL)
		return;
	inOrder(root->left);
	std::cout << "(" << root->item << ", " << root->count << ")";
	inOrder(root->right);
}


void Tree::findDiameterOfTree(Node * root, int & l, int & r, int hd)
{
	if (root == nullptr) {
		return;
	}
	if (hd < l)
		l = hd;
	else if (hd > r)
		r = hd;
	findDiameterOfTree(root->left, l, r, hd - 1);
	findDiameterOfTree(root->right, l, r, hd + 1);
}


void Tree::verticalOrderUtil(Node * root, int curr, int i)
{
	if (root == NULL)
		return;
	if (curr == i)
		std::cout << root->item << " ";
	verticalOrderUtil(root->left, curr - 1, i);
	verticalOrderUtil(root->right, curr + 1, i);
}


void Tree::printVerticalOrder(Node * root)
{
	int l = 0, r = 0;
	findDiameterOfTree(root, l, r, 0);
	
	for (int i = l; i <= r; i++) {
		verticalOrderUtil(root, 0, i);
		std::cout << std::endl;
	}
}


int Tree::countNoOfNodes(Node *root) {
	if (root == NULL)
		return 0;
	return 1 + countNoOfNodes(root->left) + countNoOfNodes(root->right);
}


void Tree::findPreAndSucc(Node * root, Node * &pre, Node * &succ, int val)
{
	if (root == nullptr)
		return;
	if (root->item > val) {
		succ = root;
		findPreAndSucc(root->left, pre, succ, val);
	}
	else if (root->item < val) {
		pre = root;
		findPreAndSucc(root->right, pre, succ, val);
	}
	else if (root->item == val) {
		findPreAndSucc(root->left, pre, succ, val);
		findPreAndSucc(root->right, pre, succ, val);
	}
}


void Tree::findAllWithinLimits(Node * root, int & ll, int & hl, std::vector<int>& sumAll)
{
	if (root == nullptr)
		return;
	if (root->item > hl) {
		findAllWithinLimits(root->left, ll, hl, sumAll);
	}
	else if (root->item < ll) {
		findAllWithinLimits(root->right, ll, hl, sumAll);
	}
	else if (root->item >= ll && root->item <= hl) {
		findAllWithinLimits(root->left, ll, hl, sumAll);
		sumAll.push_back(root->item);
		findAllWithinLimits(root->right, ll, hl, sumAll);
	}
}


Node * Tree::findMin(Node * root)
{
	if (root->left == NULL)
		return root;
	return findMin(root->left);
}

Node *Tree::kLargestElement(Node *root, int k) 
{
	if (root == NULL)
		return NULL;
	int rank = (root->left != NULL) ? root->left->count + 1 : root->count;
	
	if (rank == k) {
		return root;
	}
	else if (rank > k) {
		return kLargestElement(root->left, k);
	}
	else if (rank < k) {
		return kLargestElement(root->right, k - rank);
	}
}


Node *Tree::insert_elem(Node *root, int key) {
	if (root == NULL) {
		return new Node(key);
	}
	if (root->item > key) {
		root->left = insert_elem(root->left, key);
		root->count += 1;
	}
	else {
		root->right = insert_elem(root->right, key);
		root->count += 1;
	}
	return root;
}


Node * Tree::delete_elem(Node *root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->item > key) {
		root->left = delete_elem(root->left, key);
		root->count--;
	}
	else if (root->item < key) {
		root->right = delete_elem(root->right, key);
		root->count--;
	}
	else {
		if (root->left == NULL) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Node *temp = root->left;
			delete root;
			return temp;
		}
		Node *del = findMin(root->right);
		root->item = del->item;
		root->count--;
		root->right = delete_elem(root->right,del->item);
	}
	return root;
}


Node * Tree::search(Node *root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->item == key) {
		return root;
	}
	else if (root->item > key) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}
}
