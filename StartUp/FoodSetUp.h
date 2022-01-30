#pragma once
#include "Constants.h"
#include "ConsoleSetUp.h"

bool CheckFoodX(int** snake, int length, int x)
{
	if (x == 0 || x == CONSOLE_WIDTH - 1)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (snake[1][0] == x)
		{
			return false;
		}
	}

	return true;
}

bool CheckFoodY(int** snake, int length, int y)
{
	if (y == 0 || y == CONSOLE_HEIGHT - 1)
	{
		return false;
	}

	for (int i = 0; i < length; i++)
	{
		if (snake[1][0] == y)
		{
			return false;
		}
	}

	return true;
}

void ShowFood(int food[2])
{
	SetCursor(food[0], food[1]);
	std::cout << 'F';
}

bool CheckIfFoodEaten(int** snake, int length, int food[2])
{
	if (snake[0][0] == food[0] && snake[0][1] == food[1])
	{
		return true;
	}

	return false;
}