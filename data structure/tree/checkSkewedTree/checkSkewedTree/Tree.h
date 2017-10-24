#pragma once
#include "Node.h"

#include <iostream>
#include <climits>
#include <algorithm>

class Tree
{
private:
	Node *findMin(Node *root);
	void findWidthAndPrint(Node *root, int w, int cw);
	void findDepthAndPrint(Node *root, int d, int cd);
	int findDepth(Node *root);
	void findMinAndMAX(Node *root, int &min, int &max, int hd);

public:
	Node *root;
	int count;
	Tree();
	Node *insertKey(Node *root, int key);
	Node *deleteKey(Node *root, int key);
	Node *search(Node *root, int key);
	void inorder(Node *root);
	void inorderDepthTraversal(Node *root);
	void inorderBreadthTraversal(Node *root);
};

