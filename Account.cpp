#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "Account.h"
#include "Transaction.h"

//Account class
Account& Account::operator + (Account& obj)
{
	this->setBalance(this->getBalance() + obj.getBalance());
	return *this;
}


void Account::setBalance(double b)   //Setting balance
{
	balance = b;
}
double Account::getBalance()    //Getting balance
{
	return balance;
}

void Account::setHistory(Transaction* h)  //Setting history
{
	history.emplace_back(h);
}
std::vector<Transaction*> Account::getHistory()   //Getting history
{
	return history;
}

void Account::setType(int t)
{
	type = t;
}

int Account::getType()
{
	return type;
}

void Account::setIndex(int i)
{
	index = i;
}

int Account::getIndex()
{
	return index;
}

Account* Account::open(Account* c, std::vector<Account*> openedAccounts, double amount)
{
	//Finding current date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	//Making a new transaction object
	Transaction* t = new Transaction(" id", dt, amount);

	//Adding transaction details to history
	c->setHistory(t);


	return c;
}







