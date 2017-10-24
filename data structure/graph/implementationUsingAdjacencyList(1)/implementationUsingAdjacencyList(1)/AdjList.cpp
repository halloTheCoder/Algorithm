#include "stdafx.h"
#include "AdjList.h"
#include "Node.h"
#include <iostream>

AdjList::AdjList(int v)
{
	this->v = v;
	table = new Node *[v];
	for (int i = 0; i < v; i++) 
		table[i] = nullptr;
}


AdjList::~AdjList()
{
	for (int i = 0; i < v; i++)
		delete table[i];
	delete[] table;
}

void AdjList::addEdge(int src, int dest)
{
	if (table[src] == nullptr) {
		table[src] = new Node(0);
		table[src]->value++;
		table[src]->next = new Node(dest);
	}
	else {
		Node *p = table[src]->next;
		table[src]->value++;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new Node(dest);
	}
}

void AdjList::printAdjList()
{
	for (int i = 0; i < v; i++) {
		if (table[i] == nullptr)
			continue;
		Node *p = table[i]->next;
		std::cout << i << " :: Count = " << table[i]->value << " :: Head ";
		while(p != nullptr) {
			std::cout << " -> " << p->value;
			p = p->next;
		}
		std::cout << std::endl;
	}
}
