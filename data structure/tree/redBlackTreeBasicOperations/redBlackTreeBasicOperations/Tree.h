#pragma once
#include "Node.h"

class Tree
{
private:
	Node *BSTInsert(Node *root, int key);
	Node *searchKey(Node *root, int key);
	void leftRotate();
	void rightRotate();

public:
	Tree();
	Node *RBTInsert(Node *root,int key);
	~Tree();
};

