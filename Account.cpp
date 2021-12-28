#include <iostream>
#include <vector>
#include "Account.h"
#include "Transaction.h"


void Account::setBalance(int b)   //Setting balance
{
	balance = b;
}
int Account::getBalance()    //Getting balance
{
	return balance;
}

void Account::setHistory(std::vector<Transaction> h)  //Setting history
{
	history.emplace_back(h);
}
std::vector<Transaction> Account::getHistory()   //Getting history
{
	return history;
}

void Account::setType(std::string t)
{
	type = t;
}

std::string Account::getType()
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




void Account::toString()
{
	std::cout << "1" << std::endl;
}




void Current::deposit()
{
	std::cout << "1" << std::endl;
}

void Current::toString()
{
	std::cout << "1" << std::endl;
}

void Current::withdraw()
{
	std::cout << "1" << std::endl;
}




void Savings::setInterestRate(int ir)   //Setting balance
{
	interestRate = ir;
}
int Savings::getInterestRate()    //Getting balance
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

void Savings::computeInterest()
{
	std::cout << "1" << std::endl;
}

void Savings::deposit()
{
	std::cout << "1" << std::endl;
}

void Savings::toString()
{
	std::cout << "1" << std::endl;
}

void Savings::withdraw()
{
	std::cout << "1" << std::endl;
}
