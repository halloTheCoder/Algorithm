#pragma once
class Node
{
public:
	int value;
	char colour;
	Node *left, *right,*parent;
	Node(int value,char colour,Node *root);
};

