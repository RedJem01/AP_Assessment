#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "Account.h"
#include "Transaction.h"

//Account class
Account::Account(double a, int b, int c)
{
	balance = a;
	index = b;
	type = c;
}

Account& Account::operator + (Account& obj)
{
	this->setBalance(this->getBalance() + this->getBalance());
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

Account* Account::open(int type, Account* c, std::vector<Account*> openedAccounts, int index, int amount)
{
	//Setting index
	index += 1;
	c->setIndex(index);

	//Setting type
	c->setType(type);

	//Setting balance
	c->setBalance(amount);

	//Making a new transaction object
	Transaction* t = new Transaction();

	//Finding current date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	//Setting attributes for transaction
	t->setDesc("id");
	t->setTimeStamp(dt);
	t->setValue(amount);

	//Adding transaction details to history
	c->setHistory(t);

	delete t;

	return c;
}




//Current class
Current::Current(int a)
{
	overdraft = a;
}

void Current::deposit(std::vector <Account*> openedAccounts, int place, double amount)
{
	//Finding current date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	//Adding the amount to the account balance
	openedAccounts[place]->setBalance(openedAccounts[place]->getBalance() + amount);

	//Creating a transaction object to add to history
	Transaction* t = new Transaction();
	t->setDesc("d");
	t->setTimeStamp(dt);
	t->setValue(amount);
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
	Transaction* t = new Transaction();
	t->setDesc("d");
	t->setTimeStamp(dt);
	t->setValue(amount);
	openedAccounts[place]->setHistory(t);
}




//Savings class
Savings::Savings(double a, bool b)
{
	interestRate = a;
	isa = b;
}

void Savings::setInterestRate(double ir)   //Setting balance
{
	interestRate = ir;
}
double Savings::getInterestRate()    //Getting balance
{
	return interestRate;
}

void Savings::setIsa(bool i)   //Setting balance
{
	isa = i;
}
int Savings::getIsa()    //Getting balance
{
	return isa;
}

double Savings::computeInterest(double interestRate, double balance, double time)
{
	double finalAmount;
	double notimes = 12;
	double nt = 12 * time;
	//Middle of the brackets
	double mid = (interestRate / notimes) + 1;
	finalAmount = balance * (std::pow(mid, nt));
	return finalAmount;
}

void Savings::deposit(std::vector <Account*> openedAccounts, int place, double amount)
{
	//Finding current date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	//Adding the amount to the account balance
	openedAccounts[place]->setBalance(openedAccounts[place]->getBalance() + amount);

	//Creating a transaction object to add to history
	Transaction* t = new Transaction();
	t->setDesc("d");
	t->setTimeStamp(dt);
	t->setValue(amount);
	openedAccounts[place]->setHistory(t);
}

void Savings::withdraw(std::vector <Account*> openedAccounts, int place, double amount)
{
	//Finding current date and time
	time_t now = time(0);
	char* dt = ctime(&now);

	//Minus the amount from the balance
	openedAccounts[place]->setBalance(openedAccounts[place]->getBalance() - amount);

	//Creating a transaction object to add to history
	Transaction* t = new Transaction();
	t->setDesc("d");
	t->setTimeStamp(dt);
	t->setValue(amount);
	openedAccounts[place]->setHistory(t);
}
