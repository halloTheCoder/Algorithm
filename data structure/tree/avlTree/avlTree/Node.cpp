#include "stdafx.h"
#include "Node.h"


Node::Node(int value,int w)
{
	this->w = w;
	this->left = nullptr;
	this->right = nullptr;
	this->value = value;
}

