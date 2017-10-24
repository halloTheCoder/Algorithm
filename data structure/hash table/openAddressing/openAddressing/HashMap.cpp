#include "stdafx.h"
#include "HashMap.h"
#include "HashEntry.h"

#include <iostream>

int hashFunction(int k) {
	return k % 7;
}

HashMap::HashMap():tableSize(7)
{
	table = new HashEntry *[tableSize];
	for (int i = 0; i < tableSize; i++)
		table[i] = nullptr;
}


HashMap::~HashMap()
{
	for (int i = 0; i < tableSize; i++)
		delete table[i];
	delete[] table;
}

void HashMap::remove(int k)
{
	if (search(k) == -1) {
		std::cout << "NOT FOUND!!!!" << std::endl;
		return;
	}
	else {
		table[search(k)]->key = -1;
	}
}

void HashMap::insert(int k)
{
	/*if (count >= this->tableSize) {
		std::cout<<"FAILED!!!!"<<std::endl;
		return;
	}*/
	int hash = hashFunction(k);
	while (table[hash] != nullptr && table[hash]->value != k)
	{
		hash = hashFunction(hash + 1);
	}
	//count++;
	table[hash] = new HashEntry(1, k);
}

int HashMap::search(int k)
{
	int  hash = hashFunction(k);
	while ((table[hash] != nullptr || table[hash]->key == -1) && table[hash]->value != k)
	{
		hash = hashFunction(hash + 1);
	}
	if (table[hash] == nullptr)
		return -1;
	else
		return hash;
}
