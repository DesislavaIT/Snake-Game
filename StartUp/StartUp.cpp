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
	for (int i = 0; i < length; i++)
	{
		snake[i] = new int[2];// for x & y
	}

	snake[5] = nullptr;

	int direction = 1;
	//1 = right
	//2 = down
	//3 = left
	//4 = up

	for (int i = 0; i < length; i++)
	{
		snake[i][0] = i + 1;
		snake[i][1] = 1;
	}

	ShowSnake(snake, length);

	for (int i = 0; i < length; i++)
	{
		delete[] snake[i];
	}

	delete[] snake;
	return 0;
}