#include "stdafx.h"
#include "Node.h"


Node::Node(int item)
{
	this->item = item;
	this->count = 1;
	this->left = NULL;
	this->right = NULL;
}

