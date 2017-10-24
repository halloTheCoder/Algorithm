#pragma once
#include "Node.h"

class Tree
{
private:
	Node *findMin(Node *root);
public:
	Node *root;
	int count;
	Tree();
	Node *insertKey(Node *root, int key, char color = 'r');
	Node *deleteKey(Node *root, int key);
	Node *search(Node *root, int key);
	void inorder(Node *root);
	int maxDepth(Node *root);
	void verticalOrder(Node *root, int i, int d);
	void printLevelOrder(Node *root);
	int blackHeight(Node *root);
	Node *leftRotate(Node *x);
	Node *rightRotate(Node *y);
};

