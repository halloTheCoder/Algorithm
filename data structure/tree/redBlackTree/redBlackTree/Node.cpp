#include "stdafx.h"
#include "Node.h"


Node::Node(int value,char colour,Node *root)
{
	this->left = nullptr;
	this->right = nullptr;
	this->value = value;
	this->parent = root;
	this->colour = colour;
}

