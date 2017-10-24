#pragma once
#include "Node.h"

class Tree
{
private:
	Node *findMin(Node *root);
	int maxDepth(Node *root);
	void verticalOrder(Node *root, int i, int d);
public:
	Node *root;
	int count;
	Tree();
	Node *insertKey(Node *root, int key);
	Node *deleteKey(Node *root, int key);
	Node *search(Node *root, int key);
	void inorder(Node *root);
	void printLevelOrder(Node *root);
};

