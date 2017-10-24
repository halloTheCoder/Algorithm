#include "stdafx.h"
#include "Tree.h"


Tree::Tree()
{
}

Node * Tree::BSTInsert(Node * root, int key)
{
	if (root == nullptr) {
		return new Node(key);
	}
	if (root->key > key) {
		root->left = BSTInsert(root->left, key);
		root->left->parent = root;
	}
	else if (root->key < key) {
		root->right = BSTInsert(root->right, key);
		root->right->parent = root;
	}
	return root;
}

Node * Tree::searchKey(Node *root, int key) {
	if (root == nullptr) {
		return root;
	}
	if (root->key == key)
		return root;
	if (root->key > key)
		return searchKey(root->left, key);
	else if (root->key < key)
		return searchKey(root->right, key);
	return root;
}

Node * Tree::RBTInsert(Node * root, int key)
{
	BSTInsert(root, key);
	Node *index = searchKey(root, key);
	while (index != root && index->colour == 'r') {
		if (index->parent->colour == 'r') {
			Node *parent = index->parent;
			Node *grandParent = parent->parent;
			Node *uncle;
			if (parent = grandParent->left)
				uncle = grandParent->right;
			else
				uncle = grandParent->left;

			if (uncle->colour == 'r') {
				parent->colour = 'b';
				uncle->colour = 'b';
				grandParent->colour = 'r';
				index = grandParent;
			}
			else{
				if (index == parent->left && parent == grandParent->left){
					case1(parent);
					index = grandParent;
				}
				else if (index == parent->right && parent == grandParent->left) {
					leftRotate(index);
					case1(index);
					index = grandParent;
				}
				if (index == parent->right && parent == grandParent->right) {
					case2(parent);
					index = grandParent;
				}
				else if (index == parent->left && parent == grandParent->right) {
					rightRotate(index);
					case2(index);
					index = grandParent;
				}
			}
		}
	}
	root->colour = 'b';
	return root;
}


Tree::~Tree()
{
}
