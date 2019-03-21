#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#include <iostream>
#include <windows.h>

void ShowMenu();
void PrintBorders();
void GetConsoleInfo(CONSOLE_SCREEN_BUFFER_INFO* csbi);
void ConsoleGoTo(short x, short y);

#endif
