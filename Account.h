#ifndef Account_h
#define Account_h
#include "Transaction.h"

class Account
{
private:
	double balance = 0;
	std::vector<Transaction*> history;
	std::string type;
	int index = 0;

public:
	void setBalance(double b);   //Setting balance

	double getBalance();    //Getting balance

	void setHistory(Transaction* h);  //Setting history

	std::vector<Transaction*> getHistory();   //Getting history

	void setType(std::string t);  //Setting type

	std::string getType();  //Getting type

	void setIndex(int i); //Setting index

	int getIndex(); // Getting index


	void virtual deposit(std::vector <Account*> openedAccounts, int place, double amount) = 0;

	void virtual withdraw(std::vector <Account*> openedAccounts, int place, double amount) = 0;
};

class InterestEarning
{
public:
	double virtual computeInterest(double interestRate, double balance, double time) = 0;
};

class Current : public Account
{
public:
	int overdraft = 500;

	void deposit(std::vector <Account*> openedAccounts, int place, double amount);

	void withdraw(std::vector <Account*> openedAccounts, int place, double amount);
};

class Savings : public Account, public InterestEarning
{
protected:
	int interestRate = 0;
	bool isa = false;

public:
	void setInterestRate(double ir);  //Setting balance

	double getInterestRate();    //Getting balance

	void setIsa(bool i);   //Setting balance

	int getIsa();   //Getting balance

	double computeInterest(double interestRate, double balance, double time);

	void deposit(std::vector <Account*> openedAccounts, int place, double amount);

	void withdraw(std::vector <Account*> openedAccounts, int place, double amount);
};

#endif

