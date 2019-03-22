#ifndef BANK_BALANCE_H
#define BANK_BALANCE_H

#include <iostream>
#include <windows.h>
#include "MenuHandler.h"

typedef long double money_t;

class BankBalance
{
	public:
		BankBalance(short pinCode);
		void Start();
		void PrintReturnOption();
	private:
		money_t GetBalance();
		void Back();
};

#endif
