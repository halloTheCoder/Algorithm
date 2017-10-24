// openAddressing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HashEntry.h"
#include "HashMap.h"

#include <iostream>


int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	HashMap hash;
	int key, value;
	int choice;
	while (1)
	{
		cout << "\n----------------------" << endl;
		cout << "Operations on Hash Table" << endl;
		cout << "\n----------------------" << endl;
		cout << "1.Insert element into the table" << endl;
		cout << "2.Search element from the key" << endl;
		cout << "3.Delete element at a key" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> value;
			hash.insert(value);
			break;
		case 2:
			cout << "Enter element to be searched: ";
			cin >> key;
			if (hash.search(key) == -1)
			{
				cout << "No element found " << key << endl;
				continue;
			}
			else
			{
				cout << "Element " << key <<" at position"<< " : ";
				cout << hash.search(key) + 1 << endl;
			}
			break;
		case 3:
			cout << "Enter element to be deleted: ";
			cin >> key;
			hash.remove(key);
			break;
		case 4:
			exit(1);
		default:
			cout << "\nEnter correct option\n";
		}
	}
    return 0;
}

