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

	int direction = 1; //initial direction is right
	//1 = right
	//2 = down
	//3 = left
	//4 = up

	for (int i = length - 1, j = 0; i >= 0; i--, j++)
	{
		snake[i][0] = j + 1;
		snake[i][1] = 1;
	}

	ShowSnake(snake, length);
	int counter = 1;

	while (true)
	{
		switch (direction)
		{
		case 1:
			MoveRight(snake, length);
			break;
		case 2:
			MoveDown(snake, length);
			break;
		case 3:
			MoveLeft(snake, length);
			break;
		case 4:
			MoveUp(snake, length);
			break;
		}
		ShowSnake(snake, length);
		Sleep(500);
		counter++;
		if (counter > 10 && counter <= 20)
		{
			direction = 2;
		}
		if (counter > 20 && counter <= 30)
		{
			direction = 3;
		}
		if (counter > 30 && counter <= 40)
		{
			direction = 4;
		}

		if (counter > 40)
		{
			break;
		}
	}

	for (int i = 0; i < length; i++)
	{
		delete[] snake[i];
	}

	delete[] snake;
	return 0;
}