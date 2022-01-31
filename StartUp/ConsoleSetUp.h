#pragma once
#include <windows.h>
#include "Constants.h"
#define _WIN32_WINNT 0x0500

using namespace std;

void SetConsoleSize()
{
	HANDLE hOut;
	SMALL_RECT DisplayArea = { 0, 0, 0, 0 };
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DisplayArea.Right = CONSOLE_WIDTH - 1;
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
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};

	SetConsoleScreenBufferSize(handle, new_size);
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

void MakeCursorInvisible()
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ci;
	ci.dwSize = 100;
	ci.bVisible = FALSE;
	SetConsoleCursorInfo(output, &ci);
}

void PrintFrame()
{
	SetConsoleTextAttribute(handle, 14);
	cout << (char)(219);
	for (int i = 1; i < CONSOLE_WIDTH - 1; i++)
	{
		cout << (char)(223);
	}
	cout << (char)(219) << endl;

	for (int j = 0; j < CONSOLE_HEIGHT - 2; j++)
	{
		cout << (char)(219);
		for (int i = 0; i < CONSOLE_WIDTH - 2; i++)
		{
			cout << ' ';
		}
		cout << (char)(219) << endl;
	}

	cout << (char)(219);
	for (int i = 1; i < CONSOLE_WIDTH - 1; i++)
	{
		cout << (char)(220);
	}
	cout << (char)(219);
}