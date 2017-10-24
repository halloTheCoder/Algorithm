#include "stdafx.h"
#include "HashMap.h"
#include "HashNode.h"

#include <iostream>

HashMap::HashMap():tableSize(7)
{
	table = new HashNode *[tableSize];
	for (int i = 0; i < tableSize; i++)
		table[i] = nullptr;
}


HashMap::~HashMap()
{
	for (int i = 0; i < tableSize; i++)
		delete table[i];
	delete[] table;
}

void HashMap::insert(int k)
{
	int hash = hashFunc(k);
	if (table[hash] == nullptr) {
		table[hash] = new HashNode(k);
	}
	else {
		HashNode *p = table[hash];
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new HashNode(k);
	}
}

int HashMap::search(int k)
{
	int count = 0;
	int hash = hashFunc(k);
	if (table[hash] == nullptr)
		return -1;
	count++;
	HashNode *p = table[hash];
	while (p != nullptr && p->value != k) {
		p = p->next;
		count++;
	}
	if (p == nullptr)
		return -1;
	else
		return count;
}

void HashMap::remove(int k)
{
	int hash = hashFunc(k);
	if (search(k) == -1) {
		std::cout << "NOt fouND!!!!" << std::endl;
		return;
	}
	if (search(k) == 1) {
		table[hash] = table[hash]->next;
	}
	else {
		HashNode *c = table[hash];
		HashNode *p = nullptr;
		while (c->next != nullptr && c->value != k) {
			p = c;
			c = c->next;
		}
		if (c->next == nullptr && c->value != k) {
			std::cout << "NOt fouND!!!!" << std::endl;
			return;
		}
		else {
			p->next = c->next;
		}
	}
}
