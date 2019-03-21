#include "MenuHandler.h"

void ShowMenu()
{
	PrintBorders();
	
	ConsoleGoTo(0, 0); // Move cursor to console begining
	
	std::cin.get();
}

void PrintBorders()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; // Console info
	
	GetConsoleInfo(&csbi); // Populate csbi
	
	// Getting columns and rows from csbi
	int consoleColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	
	// Top and bottom borders
	for (int i = 0; i < consoleColumns; i++)
	{
		// Top
		ConsoleGoTo(i, 0); // x = column number, y = 0
		std::cout << "#";
		// Bottom
		ConsoleGoTo(i, consoleRows - 1); // x = column number, y = total of rows
		std::cout << "#";
	}
	
	// Left and right border
	for (int i = 0; i < consoleRows; i++)
	{
		// Left
		ConsoleGoTo(0, i); // x = 0, y = row number
		std::cout << "#";
		// Right
		ConsoleGoTo(consoleColumns - 1, i); // x = total of columns, y = row number
		std::cout << "#";
	}
}

void GetConsoleInfo(CONSOLE_SCREEN_BUFFER_INFO* csbi)
{
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), csbi); // Populate console info variable
}

void ConsoleGoTo(short x, short y)
{
	COORD newPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newPosition);
}
