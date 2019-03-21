#include "MenuHandler.h"

void ShowMenu()
{
	PrintBorders();
	
	// First menu option
	PrintOption("Bank Balance", { 5, 4 });
	PrintOption("Withdraw", { 5, 8 });
	
	std::cin.get();
}

void PrintOption(std::string optionName, COORD initCoords)
{
	int centeringSpace = 2;
	
	ConsoleGoTo(initCoords.X, initCoords.Y);
	// Top border
	for (int i = 0; i < optionName.size() + centeringSpace; i++)
	{
		std::cout << "=";
	}
	
	ConsoleGoTo(initCoords.X + 1, initCoords.Y + 1);
	ConsoleTextColor(CONSOLE_GREEN);
	std::cout << optionName.substr(0, 1); // First letter
	ConsoleTextColor(CONSOLE_WHITE);
	std::cout << optionName.substr(1, optionName.size()); // Rest of the option name
	
	// Bottom border
	ConsoleGoTo(initCoords.X, initCoords.Y + 2);
	for (int i = 0; i < optionName.size() + centeringSpace; i++)
	{
		std::cout << "=";
	}
}

void PrintBorders()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi; // Console info
	
	GetConsoleInfo(&csbi); // Populate csbi
	
	// Getting columns and rows from csbi
	int consoleColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	
	// Top and bottom borders
	for (int i = MARGIN; i < consoleColumns - MARGIN; i++)
	{
		// Top
		ConsoleGoTo(i, MARGIN); // x = column number, y = 0
		std::cout << "#";
		// Bottom
		ConsoleGoTo(i, consoleRows - 1 - MARGIN); // x = column number, y = total of rows
		std::cout << "#";
	}
	
	// Left and right border
	for (int i = MARGIN; i < consoleRows - MARGIN; i++)
	{
		// Left
		ConsoleGoTo(MARGIN, i); // x = 0, y = row number
		std::cout << "#";
		// Right
		ConsoleGoTo(consoleColumns - 1 - MARGIN, i); // x = total of columns, y = row number
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

void ConsoleTextColor(int colorAttribute)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorAttribute);
}
