#pragma once
#include "Constants.h"

int** ResizeSnake(int** snake, int& length)
{
	int oldLength = length;
	length += SNAKE_LENGTH;
	int** newSnake = new int* [length];
	for (int i = 0; i < oldLength; i++)
	{
		newSnake[i] = new int[2];
		for (int j = 0; j < 2; j++)
		{
			newSnake[i][j] = snake[i][j];
		}
	}

	snake[oldLength] = nullptr;
	for (int i = 0; i < oldLength; i++)
	{
		delete[] snake[i];
	}

	delete[] snake;

	return newSnake;
}
