#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Account.cpp"
#include "Transaction.cpp"

int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;
	std::vector <Account*> openedAccounts;
	bool caOpened = false;

	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;

	while (userCommand != "exit")
	{
		parameters.clear(); // clear ready for next command
		std::cout << std::endl << ">>> ";

		std::getline(std::cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		// Define all commands as per the brief
		std::string command = parameters[0];

		if (command.compare("options") == 0)
		{
			// display the various commands to the user
			std::cout << "Options - Shows all of the commands\nOpen - Opens a new bank account\nView - Shows a bank account balance and recent transactions\nWithdraw - Withdraws an amount from the bank account \n Deposit - Deposits an amount into the bank account\nTransfer - Transfers an amount between bank accounts\nProject - Finds the compound interest after an amount of years" << std::endl;
		}
		else if (command.compare("open") == 0)
		{
			// allow a user to open an account
			std::string accountChoice;
			int i;
			std::cout << "What kind of account would you like to open? Please input 1 for a current account, 2 for a regular savings acount or 3 for an ISA savings account." << std::endl;
			std::getline(std::cin, accountChoice);   //User input what kind of account
			if (accountChoice == "1")   //If current account
			{
				if (caOpened == true)
				{
					std::cout << "A current accont already exists. Please choose a different type of account" << std::endl;
					main();
				}
				Account* c = new Current();
				std::cout << "How much would you like to open this bank with?" << std::endl;
				std::cin >> i;
				c->setBalance(i);
				openedAccounts.emplace_back(c);
				caOpened = true;
			}
		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
		}
		else if (command.compare("withdraw") == 0)
		{
			// allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}

	}

	std::cout << "Press any key to quit...";
	std::getchar();
}

