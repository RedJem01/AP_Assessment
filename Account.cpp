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

void Current::withdraw(std::vector <Account> openedAccounts, int place)
{
	bool loop2 = true;

	//input verification 
	while (loop2 == true)
	{
		//Inputting amount to withdraw
		std::cout << "Please input the amount you want to withdraw." << std::endl;
		int amount;
		std::cin >> amount;

		//If the amount to withdraw is more than balance and overdraft
		if ((openedAccounts[place].getBalance() + 500) < amount)
		{
			std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
		}
		//If the amount is less than the balance
		else
		{
			//Minus the amount from the balance
			openedAccounts[place].setBalance(openedAccounts[place].getBalance() - amount);

			//End loop
			loop2 = false;
		}
	}
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

void Savings::withdraw(std::vector <Account> openedAccounts, int place)
{
	bool loop2 = true;

	//Second input verification 
	while (loop2 == true)
	{
		//Inputting amount to withdraw
		std::cout << "Please input the amount you want to withdraw." << std::endl;
		int amount;
		std::cin >> amount;

		//If the amount is more than the balance
		if (openedAccounts[place].getBalance() < amount)
		{
			std::cout << "The amount you want to withdraw is more than the amount in your account. Please choose  smaller amount." << std::endl;
		}
		//If the amount is less than the balance
		else
		{
			//Minus the amount from the balance
			openedAccounts[place].setBalance(openedAccounts[place].getBalance() - amount);

			//End loop
			loop2 = false;
		}
	}
}
