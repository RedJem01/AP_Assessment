#include <iostream>
#include <vector>
#include "Transaction.cpp"

class Account
{
	private:
		int balance;
		std::vector<Transaction> history;

	public:
		void setBalance(int b)   //Setting balance
		{
			balance = b;
		}
		int getBalance()    //Getting balance
		{
			return balance;
		}

		void setHistory(std::vector<Transaction> h)  //Setting history
		{
			history = h;
		}
		std::vector<Transaction> getHistory()   //Getting history
		{
			return history;
		}

		void virtual deposit()
		{

		}

		void toString()
		{

		}

		void virtual withdraw()
		{

		}

};

class InterestEarning
{
	public:
		void virtual computeInterest()
		{

		}
};

class Current : public Account
{
	public:
		int overdraft;

	public:
		void deposti()
		{

		}

		void toString()
		{

		}

		void withdraw()
		{

		}
};

class Savings : public Account, public InterestEarning
{
	protected:
		int interestRate;
		bool isa;

	public:
		void computeInterest()
		{

		}

		void deposit()
		{

		}

		void toString()
		{

		}

		void withdraw()
		{

		}
};