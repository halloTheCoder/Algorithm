// redBlackTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"

#include <iostream>

#define nL std::cout<<std::endl;

int main()
{
	Node *root = nullptr;
	Tree t;
	/* Constructing tree given in the above figure */
	root = t.insertKey(root, 7 , 'b');
	root = t.insertKey(root, 3);
	root = t.insertKey(root, 18);
	root = t.insertKey(root, 10);
	root = t.insertKey(root, 22);
	root = t.insertKey(root, 8);
	root = t.insertKey(root, 11);
	root = t.insertKey(root, 26);
	root = t.insertKey(root, 15);

	printf("Level Order traversal of the constructed AVL"
		" tree is \n");
	t.printLevelOrder(root);

	nL;

	system("pause");
    return 0;
}

