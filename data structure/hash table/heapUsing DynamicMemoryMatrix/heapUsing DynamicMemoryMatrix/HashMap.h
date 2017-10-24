#pragma once

#include "HashEntry.h"

class HashMap {
private:
	HashEntry **table;
	const int tableSize = 128;
public:
	HashMap();
	~HashMap();
	void remove(int key);
	void insert(int key);
	int search(int key);
};