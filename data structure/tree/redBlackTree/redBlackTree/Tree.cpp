#include "stdafx.h"
#include "Tree.h"
#include "Node.h"

#include <iostream>
#include <algorithm>
#include <climits>

Node * Tree::findMin(Node * root)
{
	while (root->left != nullptr)
		root = root->left;
	return root;
}

Tree::Tree()
{
}

Node *Tree::insertKey(Node *root,int key,char color)
{
	if (root == nullptr) {
		Node *temp = new Node(key,color,root);
		if (temp->parent != nullptr && temp->parent->parent != nullptr && temp->parent->colour == 'r') {
			Node *gParent = temp->parent->parent, *uncle;
			if (gParent->value < temp->value)
				uncle = gParent->left;
			else
				uncle = gParent->right;
			if (uncle->colour == 'r') {
				temp->parent->colour = 'r';
				uncle->colour = 'r';
			}
		}
		return temp;
	}
	if (root->value > key) {
		root->left = insertKey(root->left, key);
		if (blackHeight(root->left) < blackHeight(root->right)) {
			rightRotate(root->left);
		}
	}
	else if(root->value < key){
		root->right = insertKey(root->right, key);
		if (blackHeight(root->left) > blackHeight(root->right)) {
			leftRotate(root->right);
		}
	}
	return root;
}

Node *Tree::rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	return x;
}

Node *Tree::leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;

	x->right = T2;
	y->left = x;

	return y;
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
	return root;
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
		std::cout << root->colour << " ";
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

int Tree::blackHeight(Node *root) {
	if (root == nullptr)
		return 1;
	return (std::max(blackHeight(root->left), blackHeight(root->right)) + ((root->colour == 'b') ? 1 : 0));
	//if (root == nullptr)
		//return 0;
	//return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
