// insertingAndDeletingpractice1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

int main()
{
	Node *root = nullptr;
	Tree t;
	root = t.insertKey(root, 50);
	root = t.insertKey(root, 30);
	root = t.insertKey(root, 20);
	root = t.insertKey(root, 40);
	root = t.insertKey(root, 70);
	root = t.insertKey(root, 60);
	root = t.insertKey(root, 80);

	printf("Inorder traversal of the given tree \n");
	t.inorder(root);

	printf("\nDelete 20\n");
	root = t.deleteKey(root, 20);
	printf("Inorder traversal of the modified tree \n");
	t.inorder(root);

	printf("\nDelete 30\n");
	root = t.deleteKey(root, 30);
	printf("Inorder traversal of the modified tree \n");
	t.inorder(root);

	printf("\nDelete 50\n");
	root = t.deleteKey(root, 50);
	printf("Inorder traversal of the modified tree \n");
	t.inorder(root);
	system("pause");
    return 0;
}

