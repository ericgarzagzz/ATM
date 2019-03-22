#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#define MARGIN 2

#define CONSOLE_GREEN 0x002
#define CONSOLE_WHITE 0x00F
#define CONSOLE_RED   0x00C

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "BankBalance.h"

void ShowMenu();
void PrintOption(std::string optionName, COORD initCoords);
void PrintBorders();
void DecideAction();
char ReadKeyAnswer();
void GetConsoleInfo(CONSOLE_SCREEN_BUFFER_INFO* csbi);
void ConsoleGoTo(short x, short y);
void ConsoleTextColor(int colorAttribute);
void ClearScreen();

#endif
