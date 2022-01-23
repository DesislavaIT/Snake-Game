#include <iostream>
#include "ConsoleSetUp.h"

using namespace std;

int main()
{
	SetConsoleSize();
	MakeConsoleUnresizable();
	SetName();

	for (int i = 0; i < CONSOLE_WIDTH; i++)
	{
		cout << '*';
	}
	cout << endl;

	for (int j = 0; j < CONSOLE_HEIGHT - 2; j++)
	{
		cout << '*';
		for (int i = 0; i < CONSOLE_WIDTH - 2; i++)
		{
			cout << ' ';
		}
		cout << '*' << endl;
	}

	for (int i = 0; i < CONSOLE_WIDTH; i++)
	{
		cout << '*';
	}

	return 0;
}