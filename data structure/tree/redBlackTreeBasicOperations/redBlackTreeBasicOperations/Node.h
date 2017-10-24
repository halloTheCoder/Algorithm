#pragma once
class Node
{
public:
	int key;
	Node *left, *right, *parent;
	char colour;
	Node(int key,char colour = 'r');
};

