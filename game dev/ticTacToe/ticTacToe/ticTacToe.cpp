// ticTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"
#include <iostream>

int main()
{
	int multiplayer;
	std::cout << "Enter PLay Type :: (1=two_player) (2=try ur luck with random) (3=try to defeat AI) " << std::endl;
	std::cin >> multiplayer;
	Board b(multiplayer, 3, 3);
	b.checkPlayerType();
	system("pause");
    return 0;
}

