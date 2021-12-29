#ifndef Account_h
#define Account_h
#include "Transaction.h"

class Account
{
private:
	double balance;
	std::vector<Transaction*> history;
	std::string type;
	int index;

public:
	void setBalance(double b);   //Setting balance

	double getBalance();    //Getting balance

	void setHistory(Transaction* h);  //Setting history

	std::vector<Transaction*> getHistory();   //Getting history

	void setType(std::string t);  //Setting type

	std::string getType();  //Getting type

	void setIndex(int i); //Setting index

	int getIndex(); // Getting index


	void virtual deposit(std::vector <Account*> openedAccounts, int place) = 0;

	void toString();

	void virtual withdraw(std::vector <Account*> openedAccounts, int place) = 0;
};

class InterestEarning
{
public:
	void virtual computeInterest() = 0;
};

class Current : public Account
{
public:
	int overdraft;

	void deposit(std::vector <Account*> openedAccounts, int place);

	void toString();

	void withdraw(std::vector <Account*> openedAccounts, int place);
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

	void deposit(std::vector <Account*> openedAccounts, int place);

	void toString();

	void withdraw(std::vector <Account*> openedAccounts, int place);
};

#endif

