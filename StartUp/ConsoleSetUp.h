#pragma once
#include <windows.h>
#include "Constants.h"
#define _WIN32_WINNT 0x0500

void SetConsoleSize()
{
	HANDLE hOut;
	SMALL_RECT DisplayArea = { 0, 0, 0, 0 };

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DisplayArea.Right = CONSOLE_WIDTH;
	DisplayArea.Bottom = CONSOLE_HEIGHT - 1;

	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
}

void MakeConsoleUnresizable()
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void HideScrollBar()
{
	HWND x = GetConsoleWindow();
	ShowScrollBar(x, SB_BOTH, FALSE);
}

void SetName()
{
	LPCWSTR name = L"Snake Game";
	SetConsoleTitle(name);
}

void SetCursor(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
