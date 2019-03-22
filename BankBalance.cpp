#include "BankBalance.h"

BankBalance::BankBalance(short pinCode)
{
	// This should validate the pin code
}

void BankBalance::Start()
{
	int middlePadding = 7;
	
	money_t currentBalance = GetBalance();
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleInfo(&csbi);
	
	// Getting columns and rows from csbi
	int consoleColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	
	int middleColumn = (consoleColumns / 2) - middlePadding;
	int middleRow = consoleRows / 2;
	
	// Print screen borders
	PrintBorders();
	
	// Move to middle of screen
	ConsoleGoTo(middleColumn, middleRow);
	
	std::cout << "Balance";
	ConsoleGoTo(middleColumn, middleRow + 2); // Move down two rows
	ConsoleTextColor(CONSOLE_GREEN); // Green text color
	std::cout << currentBalance;
	ConsoleTextColor(CONSOLE_WHITE); // White text color
	
	PrintReturnOption();
	
	char option = ReadKeyAnswer();
	
	if (option == 'B' || option == 'b') Back();
}

void BankBalance::PrintReturnOption()
{
	int extraPadding = 3;
	
	std::string optionName = "Back";
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	GetConsoleInfo(&csbi);
	
	// Getting columns and rows from csbi
	int consoleColumns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int consoleRows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	
	int rightColumn = consoleColumns - MARGIN - extraPadding - optionName.size();
	int bottomRow = consoleRows - MARGIN - extraPadding;
	
	ConsoleGoTo(rightColumn, bottomRow);
	// Print first letter with red color
	ConsoleTextColor(CONSOLE_RED);
	std::cout << optionName.substr(0, 1);
	// Print the rest with white color
	ConsoleTextColor(CONSOLE_WHITE);
	std::cout << optionName.substr(1, optionName.size());
}

money_t BankBalance::GetBalance()
{
	return 2172.82L; // Some random number
}

void BankBalance::Back()
{
	ShowMenu();
} 
