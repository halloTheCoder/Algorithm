#pragma once
#include "Node.h"

class Tree
{
public:
	Tree();
	Node *insertKey(Node *root,int k);
	void findMinAndMax(Node *root, int *min, int *max, int r);
	void printVertical(Node *root, int lineNo, int r);
	void orderVertical(Node *root);
};

