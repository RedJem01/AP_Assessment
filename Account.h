#ifndef Account_h
#define Account_h
#include "Transaction.h"

class Account
{
private:
	int balance;
	std::vector<Transaction> history;
	std::string type;
	int index;

public:
	void setBalance(int b);   //Setting balance

	int getBalance();    //Getting balance

	void setHistory(std::vector<Transaction> h);  //Setting history

	std::vector<Transaction> getHistory();   //Getting history

	void setType(std::string t);  //Setting type

	std::string getType();  //Getting type

	void setIndex(int i); //Setting index

	int getIndex(); // Getting index


	void virtual deposit() = 0;

	void toString();

	void virtual withdraw() = 0;
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

