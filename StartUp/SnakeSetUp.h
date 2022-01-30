#pragma once
#include "Constants.h"
#include "ConsoleSetUp.h"

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

void ShowSnake(int** snake, int length)
{
	for (int i = length - 1; i >= 0; i--)
	{
		int x = snake[i][0];
		int y = snake[i][1];
		SetCursor(x, y);
		cout << '$';
	}
}

void MoveRight(int** snake, int length)
{
	int x = snake[length - 1][0];
	int y = snake[length - 1][1];
	SetCursor(x, y);
	cout << ' ';
	int newX = snake[0][0] + 1;
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < 2; j++)
		{
			snake[i][j] = snake[i - 1][j];
		}
	}

	snake[0][0] = newX;
}

void MoveDown(int** snake, int length)
{
	int x = snake[length - 1][0];
	int y = snake[length - 1][1];
	SetCursor(x, y);
	cout << ' ';
	int newY = snake[0][1] + 1;
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < 2; j++)
		{
			snake[i][j] = snake[i - 1][j];
		}
	}

	snake[0][1] = newY;
}

void MoveLeft(int** snake, int length)
{
	int x = snake[length - 1][0];
	int y = snake[length - 1][1];
	SetCursor(x, y);
	cout << ' ';
	int newX = snake[0][0] - 1;
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < 2; j++)
		{
			x = snake[i - 1][0];
			y = snake[i - 1][1];
			snake[i][j] = snake[i - 1][j];
		}
	}

	snake[0][0] = newX;
}

void MoveUp(int** snake, int length)
{
	int x = snake[length - 1][0];
	int y = snake[length - 1][1];
	SetCursor(x, y);
	cout << ' ';
	int newY = snake[0][1] - 1;
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < 2; j++)
		{
			snake[i][j] = snake[i - 1][j];
		}
	}

	snake[0][1] = newY;
}

void ExtendSnake(int** snake, int length)
{
	int addElementIndex = length - 1;
}