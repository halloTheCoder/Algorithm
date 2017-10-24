#include "stdafx.h"
#include "Tree.h"
#include "Node.h"

#include <iostream>

Node * Tree::findMin(Node * root)
{
	while (root->left != nullptr)
		root = root->left;
	return root;
}

Tree::Tree()
{
}

Node *Tree::insertKey(Node *root,int key)
{
	if (root == nullptr) {
		return (new Node(key));
	}
	if (root->value > key) {
		root->left = insertKey(root->left, key);
	}
	else if(root->value < key){
		root->right = insertKey(root->right, key);
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


