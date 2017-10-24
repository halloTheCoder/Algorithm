#pragma once
#include "HashEntry.h"

class HashMap
{
private:
	HashEntry **table;
	//static int count;
	const int tableSize;
public:
	HashMap();
	~HashMap();
	void remove(int k);
	void insert(int k);
	int search(int k);
};
