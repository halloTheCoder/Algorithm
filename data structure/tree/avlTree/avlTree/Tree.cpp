#include "stdafx.h"
#include "Tree.h"
#include "Node.h"

#include <iostream>
#include <algorithm>

Node * Tree::findMin(Node * root)
{
	while (root->left != nullptr)
		root = root->left;
	return root;
}

Tree::Tree()
{
}

Node *Tree::insertKey(Node *root, int key)
{
	if (root == nullptr) {
		return (new Node(key,0));
	}
	if (root->value > key) {
		root->left = insertKey(root->left, key);
	}
	else if (root->value < key) {
		root->right = insertKey(root->right, key);
	}
	return root;
}

Node *Tree::rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->w = maxDepth(y->right) - maxDepth(y->left);
	x->w = maxDepth(x->right) - maxDepth(x->left);

	return x;
}

Node *Tree::leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	y->w = maxDepth(y->right) - maxDepth(y->left);
	x->w = maxDepth(x->right) - maxDepth(x->left);

	return y;
}

Node *Tree::insertKeyAVL(Node *root,int key)
{
	if (root == nullptr) {
		return (new Node(key,0));
	}
	int prev = root->w;
	int curr;
	if (root->value > key) {
		root->left = insertKeyAVL(root->left, key);
		root->w = maxDepth(root->right) - maxDepth(root->left);
		curr = root->w;
		if (curr == 2) {
			return leftRotate(root);
		}
		else if (curr == -2)
			return rightRotate(root);
	}
	else if(root->value < key){
		root->right = insertKeyAVL(root->right, key);
		root->w = maxDepth(root->right) - maxDepth(root->left);
		curr = root->w;
		if (curr == 2) {
			return leftRotate(root);
		}
		else if (curr == -2)
			return rightRotate(root);
	}
	return root;
}

Node *Tree::deleteKey(Node *root, int key)
{
	if (root == nullptr)
		return nullptr;
	if (root->value > key)
		root->left = deleteKey(root->left, key);
	else if (root->value > key)
		root->right = deleteKey(root->right, key);
	else {
		if (root->left == nullptr) {
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			Node *temp = root->left;
			delete root;
			return temp;
		}
		Node *temp = findMin(root->right);
		root->value = temp->value;
		root->right = deleteKey(root->right,temp->value);
	}
	return root;
}

Node *Tree::search(Node *root, int key)
{
	if (root == nullptr || root->value == key) {
		return root;
	}
	if (root->value > key)
		return search(root->left, key);
	else if (root->value < key)
		return search(root->right, key);
}

void Tree::inorder(Node *root)
{
	if (root == nullptr)
		return;
	inorder(root->left);
	std::cout << root->value << " ";
	inorder(root->right);
}

int Tree::maxDepth(Node *root) {
	if (root == nullptr)
		return 0;
	return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


void Tree::verticalOrder(Node *root, int i, int d) {
	if (root == nullptr)
		return;
	if (d == i) {
		std::cout << root->value << " ";
	}
	verticalOrder(root->left, i, d + 1);
	verticalOrder(root->right, i, d + 1);
}

void Tree::printLevelOrder(Node *root) {
	if (root == nullptr)
		return;
	int max = maxDepth(root);
	for (int i = 0; i < max; i++) {
		verticalOrder(root, i, 0);
		std::cout << std::endl;
	}
}