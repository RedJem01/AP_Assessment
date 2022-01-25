#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "Account.h"
#include "Transaction.h"
#include "Savings.h"

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
	Transaction* t = new Transaction(" d", dt, amount);
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
	Transaction* t = new Transaction(" w", dt, amount);
	openedAccounts[place]->setHistory(t);
}