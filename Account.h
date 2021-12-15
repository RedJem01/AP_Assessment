#pragma once
#ifndef Account_h
#define Account_h
#include "Transaction.h"
class Account
{
private:
	int balance;
	std::vector<Transaction> history;

public:
	void setBalance(int b);   //Setting balance

	int getBalance();    //Getting balance

	void setHistory(std::vector<Transaction> h);  //Setting history

	std::vector<Transaction> getHistory();   //Getting history


	void virtual deposit();

	void toString();

	void virtual withdraw();
};

class InterestEarning
{
public:
	void virtual computeInterest();
};

class Current : public Account
{
public:
	int overdraft;

	void deposit();

	void toString();

	void withdraw();
};

class Savings : public Account, public InterestEarning
{
protected:
	int interestRate;
	bool isa;

public:
	void setInterestRate(int ir);  //Setting balance

	int getInterestRate();    //Getting balance

	void setIsa(bool i);   //Setting balance

	int getIsa();   //Getting balance

	void computeInterest();

	void deposit();

	void toString();

	void withdraw();
};
#endif

