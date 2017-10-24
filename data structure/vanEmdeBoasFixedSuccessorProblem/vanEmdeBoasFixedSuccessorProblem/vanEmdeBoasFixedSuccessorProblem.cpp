// vanEmdeBoasFixedSuccessorProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "FixedUniverse.h"

#define u 16

int main()
{
	FixedUniverse U(u);
	U.insertElem(1);
	U.insertElem(4);
	U.insertElem(6);
	U.insertElem(9);
	U.insertElem(15);

	U.printArray();

	std::cout<<U.getSuccessor1(4)<<std::endl;
	std::cout << U.getSuccessor2(4) << std::endl;

	U.deleteElem(6);
	
	std::cout << std::endl;
	U.printArray();

	std::cout << U.getSuccessor1(4) << std::endl;
	std::cout << U.getSuccessor2(4) << std::endl;

	U.deleteElem(9);

	std::cout << std::endl;
	U.printArray();

	std::cout << U.getSuccessor1(4) << std::endl;
	std::cout << U.getSuccessor2(4) << std::endl;

	system("pause");
    return 0;
}

