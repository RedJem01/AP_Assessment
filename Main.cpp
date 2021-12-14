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
	bool isaOpened = false;

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
			bool loop = true;
			while (loop = true)   //Input verification
			{
				std::string accountChoice;
				int input;
				std::cout << "What kind of account would you like to open? Please input 1 for a current account, 2 for a regular savings acount or 3 for an ISA savings account." << std::endl;
				std::getline(std::cin, accountChoice);   //User input what kind of account
				if (accountChoice == "1")   //If current account
				{
					if (caOpened == true)
					{
						std::cout << "A current account already exists. Please choose a different type of account" << std::endl;
						main();
					}
					Account* c = new Current();   //Opening new current account
					std::cout << "How much would you like to open this account with?" << std::endl;
					std::cin >> input;
					c->setBalance(input);    //Setting account's balance as whatever is inputted
					openedAccounts.emplace_back(c);     //Putting the object into the accounts list 
					caOpened = true;    //An account has been opened so another can't be opened
					loop = false;
				}
				else if (accountChoice == "2")   //If savings account
				{
					Savings* s = new Savings();  //Opening new savings account
					s->setInterestRate(0.85);   //Setting interest rate
					s->setIsa(false);   //Setting whether or not isa
					std::cout << "How much would you like to open this account with?" << std::endl;
					std::cin >> input;
					s->setBalance(input);   
					openedAccounts.emplace_back(s);
					loop = false;
				}
				else if (accountChoice == "3")  //If ISA account
				{
					if (isaOpened == true)  //Check if it has been opened before as only 1 can be opened
					{
						std::cout << "An ISA account already exists. Please choose a different type of account" << std::endl;
						main();
					}
					bool loop2 = true;
					Savings* i = new Savings();   //Opening new ISA account through savings
					i->setInterestRate(1.15);  
					i->setIsa(true);
					while (loop2 = true)  //This is to check the opening balance is over 1000
					{ 
						std::cout << "How much would you like to open this account with? The total has to be over £1000" << std::endl;
						std::cin >> input;
						if (input < 1000)
						{
							std::cout << "That is not over £1000. Please input an amount over £1000." << std::endl;
						}
						else
						{
							loop2 = false;
						}
					}
					i->setBalance(input);
					openedAccounts.emplace_back(i);
					loop = false;
				}
				else
				{
					std::cout << "Please only input 1,2 or 3." << std::endl;
				}
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

