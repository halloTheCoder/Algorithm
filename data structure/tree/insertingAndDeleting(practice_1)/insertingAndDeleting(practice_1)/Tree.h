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
	Node *insertKey(Node *root, int key);
	Node *deleteKey(Node *root, int key);
	Node *search(Node *root, int key);
	void inorder(Node *root);
};

