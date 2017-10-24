// printBinaryTreeVertical.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"

#include <iostream>

int main()
{
	Tree t;
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->left->right = new Node(8);
	root->right->right->right = new Node(9);

	std::cout << "Vertical order traversal is \n";
	t.orderVertical(root);
	system("pause");
    return 0;
}

