#include "stdafx.h"
#include "Tree.h"
#include "Node.h"



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

Node * Tree::findMin(Node * root)
{
	while (root->left != nullptr)
		root = root->left;
	return root;
}

void Tree::inorderBreadthTraversal(Node * root)
{
	if (root == nullptr)
		return;
	int min = 0, max = 0;
	findMinAndMAX(root, min, max, 0);
	for (int i = min; i <= max; i++) {
		findWidthAndPrint(root, i, 0);
		std::cout << std::endl;
	}
}

void Tree::findWidthAndPrint(Node * root, int w, int cw)
{
	if (root == nullptr)
		return;
	if (cw == w) {
		std::cout << root->value << " ";
	}
	findWidthAndPrint(root->left, w, cw - 1);
	findWidthAndPrint(root->right, w, cw + 1);
}

void Tree::findMinAndMAX(Node * root, int & min, int & max, int hd)
{
	if (root == nullptr)
		return;
	if (hd < min) min = hd;
	if (hd > max) max = hd;
	findMinAndMAX(root->left, min, max, hd - 1);
	findMinAndMAX(root->right, min, max, hd + 1);
}

void Tree::inorderDepthTraversal(Node * root)
{
	if (root == nullptr)
		return;
	int depth = findDepth(root);
	for (int i = 0; i < depth; i++) {
		findDepthAndPrint(root, i, 0);
		std::cout << std::endl;
	}
}

void Tree::findDepthAndPrint(Node * root, int d, int cd)
{
	if (root == nullptr)
		return;
	if (cd == d) {
		std::cout << root->value << " ";
	}
	findDepthAndPrint(root->left, d, cd + 1);
	findDepthAndPrint(root->right, d, cd + 1);
}

int Tree::findDepth(Node * root)
{
	if(root == nullptr)
		return 0;
	return std::max(findDepth(root->left), findDepth(root->right)) + 1;
}
