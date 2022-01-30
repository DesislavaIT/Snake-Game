#include <iostream>
#include <cstdlib> 
#include "ConsoleSetUp.h"
#include "SnakeSetUp.h"
#include "FoodSetUp.h"
#include <conio.h>

using namespace std;

int main()
{
	HideScrollBar();
	SetConsoleSize();
	MakeConsoleUnresizable();
	SetName();
	PrintFrame();
	MakeCursorInvisible();

	int length = 5;// initial length = 5;
	int** snake = new int* [SNAKE_LENGTH];
	for (int i = 0; i < length; i++)
	{
		snake[i] = new int[2];// for x & y
	}

	snake[5] = nullptr;

	for (int i = length - 1, j = 0; i >= 0; i--, j++)
	{
		snake[i][0] = j + 1;
		snake[i][1] = 1;
	}

	ShowSnake(snake, length);
	char key = KEY_RIGHT; //initial direction is right
	char oldKey = key; //initial direction is right
	bool oppositeMessageShown = false;
	int food[2];
	int x = rand() % CONSOLE_WIDTH + 1;
	while (!CheckFoodX(snake, length, x))
	{
		x = rand() % CONSOLE_WIDTH + 1;
	}

	int y = rand() % CONSOLE_HEIGHT + 1;
	while (!CheckFoodY(snake, length, y))
	{
		y = rand() % CONSOLE_HEIGHT + 1;
	}

	food[0] = x;
	food[1] = y;
	ShowFood(food);
	while (true)
	{
		if (_kbhit())
		{
			oldKey = key;
			key = _getch();
		}

		if (oldKey == KEY_RIGHT && key == KEY_LEFT)
		{
			key = oldKey;
			if (!oppositeMessageShown)
			{
				oppositeMessageShown = true;
				MessageBox(nullptr, TEXT("You can't go in the opposite direction!"), TEXT("Attention"), MB_OK);
			}
		}

		if (oldKey == KEY_LEFT && key == KEY_RIGHT)
		{
			key = oldKey;
			if (!oppositeMessageShown)
			{
				oppositeMessageShown = true;
				MessageBox(nullptr, TEXT("You can't go in the opposite direction!"), TEXT("Attention"), MB_OK);
			}
		}

		if (oldKey == KEY_DOWN && key == KEY_UP)
		{
			key = oldKey;
			if (!oppositeMessageShown)
			{
				oppositeMessageShown = true;
				MessageBox(nullptr, TEXT("You can't go in the opposite direction!"), TEXT("Attention"), MB_OK);
			}
		}

		if (oldKey == KEY_UP && key == KEY_DOWN)
		{
			key = oldKey;
			if (!oppositeMessageShown)
			{
				oppositeMessageShown = true;
				MessageBox(nullptr, TEXT("You can't go in the opposite direction!"), TEXT("Attention"), MB_OK);
			}
		}

		switch (key)
		{
		case KEY_RIGHT:
			MoveRight(snake, length);
			break;
		case KEY_DOWN:
			MoveDown(snake, length);
			break;
		case KEY_LEFT:
			MoveLeft(snake, length);
			break;
		case KEY_UP:
			MoveUp(snake, length);
			break;
		default:
			key = oldKey;
			continue;
		}

		//Check if snake hit the boundaries
		if (snake[0][0] == 0 || snake[0][0] == CONSOLE_WIDTH - 1 || snake[0][1] == 0 || snake[0][1] == CONSOLE_HEIGHT - 1)
		{
			MessageBox(nullptr, TEXT("Game over!"), TEXT("Hit the boundaries!"), MB_OK);
			for (int i = 0; i < length; i++)
			{
				delete[] snake[i];
			}

			delete[] snake;
			exit(0);
		}

		//Check if snake bite itself
		for (int i = 1; i < length; i++)
		{
			if (snake[0][0] == snake[i][0] && snake[0][1] == snake[i][1])
			{
				MessageBox(nullptr, TEXT("Game over!"), TEXT("Bite itself!"), MB_OK);
				for (int i = 0; i < length; i++)
				{
					delete[] snake[i];
				}

				delete[] snake;
				exit(0);
			}
		}

		if (CheckIfFoodEaten(snake, length, food))
		{
			x = rand() % CONSOLE_WIDTH + 1;
			while (!CheckFoodX(snake, length, x))
			{
				x = rand() % CONSOLE_WIDTH + 1;
			}

			y = rand() % CONSOLE_HEIGHT + 1;
			while (!CheckFoodY(snake, length, y))
			{
				y = rand() % CONSOLE_HEIGHT + 1;
			}

			food[0] = x;
			food[1] = y;
			ShowFood(food);
			length++;
			if (length % SNAKE_LENGTH == 0)
			{
				snake = ResizeSnake(snake, length);
			}

			ExtendSnake(snake, length);
		}

		ShowSnake(snake, length);
		Sleep(200);
	}

	for (int i = 0; i < length; i++)
	{
		delete[] snake[i];
	}

	delete[] snake;
	return 0;
}