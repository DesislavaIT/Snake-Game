#include <iostream>
#include "ConsoleSetUp.h"
#include "SnakeSetUp.h"

using namespace std;

int main()
{
	HideScrollBar();
	SetConsoleSize();
	MakeConsoleUnresizable();
	SetName();
	PrintFrame();

	int length = 5;// initial length = 5;
	int** snake = new int* [SNAKE_LENGTH];
	for (int i = 0; i < 5; i++)
	{
		snake[i] = new int[2];// for x & y
	}

	snake[5] = nullptr;

	return 0;
}