#pragma once
#include "HashNode.h"

class HashMap
{
private:
	const int tableSize;
	HashNode **table;
public:
	HashMap();
	~HashMap();
	int hashFunc(int key) { return key % tableSize; }
	void insert(int k);
	int search(int k);
	void remove(int k);
};

