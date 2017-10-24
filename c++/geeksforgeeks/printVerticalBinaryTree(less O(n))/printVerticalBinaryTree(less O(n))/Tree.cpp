#include "stdafx.h"
#include "Tree.h"

#include <map>
#include <vector>
#include <iostream>

Tree::Tree()
{
}

void Tree::orderVertical(Node * root)
{
	std::map< int, std::vector<int> > map;
	getVerticalOrder(root, 0, map);
	for (auto it = map.begin(); it != map.end(); it++){
		for (int i = 0; i < it->second.size(); i++) {
			std::cout << it->second[i] << " ";
		}
		std::cout << std::endl;
	}
}

void Tree::getVerticalOrder(Node *root, int hd, std::map<int, std::vector<int> > &m)
{
	if (root == nullptr)
		return;
	m[hd].push_back(root->value);
	getVerticalOrder(root->left, hd - 1, m);
	getVerticalOrder(root->right, hd + 1, m);
}


