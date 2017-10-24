// avlTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include "Tree.h"

#include <iostream>

int main()
{
	Node *root = nullptr;
	Tree t;
	/* Constructing tree given in the above figure */
	root = t.insertKey(root, 12);
	root = t.insertKey(root, 8);
	root = t.insertKey(root, 18);
	root = t.insertKey(root, 5);
	root = t.insertKey(root, 11);
	root = t.insertKey(root, 17);
	root = t.insertKey(root, 4);
	root = t.insertKey(root, 7);
	root = t.insertKey(root, 2);
	root = t.insertKey(root, 1);

	printf("Level Order traversal of the constructed AVL"
		" tree is \n");
	t.printLevelOrder(root);

	std::cout << std::endl;
	
	root = nullptr;
	root = t.insertKeyAVL(root, 12);
	root = t.insertKeyAVL(root, 8);
	root = t.insertKeyAVL(root, 18);
	root = t.insertKeyAVL(root, 5);
	root = t.insertKeyAVL(root, 11);
	root = t.insertKeyAVL(root, 17);
	root = t.insertKeyAVL(root, 4);
	root = t.insertKeyAVL(root, 7);
	root = t.insertKeyAVL(root, 2);
	root = t.insertKeyAVL(root, 1);

	printf("Level Order traversal of the constructed AVL"
		" tree is \n");
	t.printLevelOrder(root);
	system("pause");
    return 0;
}

