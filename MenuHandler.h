#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#define MARGIN 2

#include <iostream>
#include <stdio.h>
#include <windows.h>

void ShowMenu();
void PrintOption(char* optionName);
void PrintBorders();
void GetConsoleInfo(CONSOLE_SCREEN_BUFFER_INFO* csbi);
void ConsoleGoTo(short x, short y);

#endif
