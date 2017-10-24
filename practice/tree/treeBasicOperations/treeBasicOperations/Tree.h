#pragma once
#include "Node.h"

#include <vector>

class Tree
{
private:
	Node *findMin(Node *root);
	void findDiameterOfTree(Node *root, int &l, int &r, int hd);
	void verticalOrderUtil(Node *root, int curr, int i);

public:
	Tree();
	void inOrder(Node *root);
	Node *kLargestElement(Node *root, int k);
	void printVerticalOrder(Node *root);
	int countNoOfNodes(Node *root);
	void findPreAndSucc(Node *root, Node * &pre, Node * &succ, int val);
	void findAllWithinLimits(Node *root, int &ll, int &hl, std::vector<int> &sumAll);
	Node *insert_elem(Node *root, int key);
	Node *delete_elem(Node *root, int key);
	Node *search(Node *root, int key);
};

