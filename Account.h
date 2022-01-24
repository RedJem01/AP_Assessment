#ifndef Account_h
#define Account_h
#include "Transaction.h"

class Account
{
private:
	double balance = 0;
	std::vector<Transaction*> history;
	int type;
	int index = 0;

public:
	Account(double a = 0, int b = 0, int c = 0);

	Account& operator + (Account& obj);

	void setBalance(double b);   //Setting balance

	double getBalance();    //Getting balance

	void setHistory(Transaction* h);  //Setting history

	std::vector<Transaction*> getHistory();   //Getting history

	void setType(int t);  //Setting type

	int getType();  //Getting type

	void setIndex(int i); //Setting index

	int getIndex(); // Getting index


	void virtual deposit(std::vector <Account*> openedAccounts, int place, double amount) = 0;

	void virtual withdraw(std::vector <Account*> openedAccounts, int place, double amount) = 0;

	Account* open(int type, Account* c, std::vector<Account*> openedAccounts, int index, int amount);
};

class InterestEarning
{
public:
	double virtual computeInterest(double interestRate, double balance, double time) = 0;
};

class Current : public Account
{
public:
	int overdraft;

	Current(int a = 0);

	void deposit(std::vector <Account*> openedAccounts, int place, double amount);

	void withdraw(std::vector <Account*> openedAccounts, int place, double amount);
};

class Savings : public Account, public InterestEarning
{
protected:
	double interestRate;
	bool isa;

public:
	Savings(double a = 0, bool b = false);

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

