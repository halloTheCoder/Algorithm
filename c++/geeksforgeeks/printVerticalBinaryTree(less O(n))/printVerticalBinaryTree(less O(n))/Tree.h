#pragma once
#include "Node.h"
#include <map>
#include <vector>

class Tree
{
public:
	Tree();
	void orderVertical(Node *root);
	void getVerticalOrder(Node *root,int hd,std::map<int , std::vector<int> > &m);
};

