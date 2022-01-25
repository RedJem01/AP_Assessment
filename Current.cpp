#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "Account.h"
#include "Transaction.h"
#include "Current.h"

void Current::deposit(std::vector <Account*> openedAccounts, int place, double amount)
{
	//Finding current date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	//Adding the amount to the account balance
	openedAccounts[place]->setBalance(openedAccounts[place]->getBalance() + amount);

	//Creating a transaction object to add to history
	Transaction* t = new Transaction("d", dt, amount);
	openedAccounts[place]->setHistory(t);
}

void Current::withdraw(std::vector <Account*> openedAccounts, int place, double amount)
{
	//Finding current date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	//Minus the amount from the balance
	openedAccounts[place]->setBalance(openedAccounts[place]->getBalance() - amount);

	//Creating a transaction object to add to history
	Transaction* t = new Transaction("w", dt, amount);
	openedAccounts[place]->setHistory(t);
}