#ifndef Account_h
#define Account_h
#include "Transaction.h"

class Account
{
protected:
	double balance;
	std::vector<Transaction*> history;
	int type;
	int index;

public:
	Account() :balance(0), type(0), index(0) {}

	Account(double a, int b, int c):balance(a), type(b), index(c){}

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

	Account* open(Account* c, std::vector<Account*> openedAccounts, double amount);
};

class InterestEarning
{
public:
	double virtual computeInterest(double interestRate, double balance, double time) = 0;
};


#endif

