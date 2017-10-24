#include "stdafx.h"
#include "HashEntry.h"
#include "HashMap.h"

#include <iostream>

int hashFunction(int key) {
	return key % 128;
}

HashMap::HashMap() {
	this->table = new HashEntry *[this->tableSize];
	for (int i = 0; i < this->tableSize; i++) {
		table[i] = nullptr;
	}
	this->count = 0;
}

void HashMap::insert(int key) {
	int index = hashFunction(key);
	int i = 0;
	while (table[index][i] != nullptr) {
		i++;
	}
	table[hashFunction(key, i - 1)] = &key;
}

int HashMap::search(int key) {
	int i = 0;
	while (table[hashFunction(key, i)] != key || hashFunction(key, i) != -1)
		i++;
	if (hashFunction(key, i) == -1) {
		return -1;
	}
	else
		return i + 1;
}

void HashMap::remove() {
	if (search(key) == -1) {
		std::cout << "Not Found" << std::endl;
		return;
	}
	else {
		table[search(key)] = 
	}
}

HashMap::~HashMap() {
	for (int i = 0; i < tableSize; i++)
		delete table[i];
	delete[] table;
}