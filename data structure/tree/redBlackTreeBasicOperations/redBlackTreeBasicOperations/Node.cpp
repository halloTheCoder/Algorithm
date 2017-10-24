#include "stdafx.h"
#include "Node.h"


Node::Node(int key,char colour)
{
	this->key = key;
	this->colour = colour;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}

