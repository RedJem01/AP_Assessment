#ifndef Savings_h
#define Savings_h
#include "Account.h"

class Savings : public Account, public InterestEarning
{
protected:
	double interestRate;
	bool isa;

public:
	Savings(double a, int b, int c)
	{
		balance = a;
		type = b;
		index = c;
	}

	Savings operator + (Savings& obj);

	void setInterestRate(double ir);  //Setting balance

	double getInterestRate();    //Getting balance

	void setIsa(bool i);   //Setting balance

	int getIsa();   //Getting balance

	double computeInterest(double interestRate, double balance, double time);

	void deposit(std::vector <Account*> openedAccounts, int place, double amount);

	void withdraw(std::vector <Account*> openedAccounts, int place, double amount);
};

#endif