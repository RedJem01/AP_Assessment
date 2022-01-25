#ifndef Current_h
#define Current_h
#include "Account.h"

class Current : public Account
{
public:
	Current(double a, int b, int c)
	{
		balance = a;
		type = b;
		index = c;
	}

	void deposit(std::vector <Account*> openedAccounts, int place, double amount);

	void withdraw(std::vector <Account*> openedAccounts, int place, double amount);
};

#endif