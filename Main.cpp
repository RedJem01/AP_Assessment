#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Account.h"
#include "Transaction.h"



int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;
	std::vector <Account> openedAccounts;
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
			bool loop = true;

			//Input verification
			while (loop = true)   
			{
				std::string accountChoice;
				int input;
				std::cout << "What kind of account would you like to open? Please input 1 for a current account, 2 for a regular savings acount or 3 for an ISA savings account." << std::endl;
				
				//User input
				std::getline(std::cin, accountChoice);  

				//If current account
				if (accountChoice == "1")   
				{
					if (caOpened == true)
					{
						std::cout << "A current account already exists. Please choose a different type of account" << std::endl;
						continue;
					}
					//Opening new current account
					Account* c = new Current();   
					c->setType("c");

					//User input
					std::cout << "How much would you like to open this account with?" << std::endl;
					std::cin >> input;
					c->setBalance(input); 

					//Making a new transaction object
					Transaction* t = new Transaction();

					//Finding current date and time
					time_t now = time(0);
					char* dt = ctime(&now);

					//Setting attributes
					t->setDesc("id");
					t->setTimeStamp(dt);
					t->setValue(input);

					//Putting object into accounts list
					openedAccounts.emplace_back(c);  

					//A current account has been opened so another can't be
					caOpened = true; 

					//Right input so end loop
					loop = false;
				}
				//If savings account
				else if (accountChoice == "2")   
				{
					//Open new savings account
					Savings* s = new Savings();  
					s->setType("s");
					s->setInterestRate(0.85);  
					s->setIsa(false);  

					//User input
					std::cout << "How much would you like to open this account with?" << std::endl;
					std::cin >> input;
					s->setBalance(input);   

					//Making a new transaction object
					Transaction* t = new Transaction();

					//Finding current date and time
					time_t now = time(0);
					char* dt = ctime(&now);

					//Setting attributes
					t->setDesc("id");
					t->setTimeStamp(dt);
					t->setValue(input);

					//Putting object into accounts list
					openedAccounts.emplace_back(s);

					//Right input so end loop
					loop = false;
				}
				//If ISA account
				else if (accountChoice == "3")  
				{
					//Check if opened before 
					if (isaOpened == true)  
					{
						std::cout << "An ISA account already exists. Please choose a different type of account" << std::endl;
						main();
					}
					bool loop2 = true;

					//Opening new ISa account through savings
					Savings* i = new Savings();   
					i->setType("i");
					i->setInterestRate(1.15);  
					i->setIsa(true);

					//Check opening balance is over £1000
					while (loop2 = true)  
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

					//Making a new transaction object
					Transaction* t = new Transaction();

					//Finding current date and time
					time_t now = time(0);
					char* dt = ctime(&now);

					//Setting attributes
					t->setDesc("id");
					t->setTimeStamp(dt);
					t->setValue(input);

					openedAccounts.emplace_back(i);
					loop = false;
				}
				else
				{
					std::cout << "Please only input 1, 2 or 3." << std::endl;
				}
			}
		}
		else if (command.compare("view") == 0)
		{
			//Display an account according to an index (starting from 1)
			std::cout << "Please provide an index for the account you want to view. If you do not know the index just press enter and all the accounts will come up." << std::endl;
			std::string viewIndex;
			std::cin >> viewIndex;

			//If no index is inputted
			if (viewIndex == "")
			{
				//Loop through account list and output all info from each account
				for (int i = 0; i < openedAccounts.size(); i++)
				{
					std::string accountType = openedAccounts[i].getType();
					if (accountType == "c")
					{
						std::cout << "Current account" << std::endl;
					}
					else if (accountType == "s")
					{
						std::cout << "Savings account" << std::endl;
					}
					else
					{
						std::cout << "ISA savings account" << std::endl;
					}
					std::cout << "Balance of account:" + openedAccounts[i].getBalance() << std::endl;
					std::cout << "Transactions:" << std::endl;
					std::vector<Transaction> ahistory = openedAccounts[i].getHistory();

					//Looping through the transactions of an account and ouput all info from each transaction
					for (int j = 0; j < ahistory.size(); j++)
					{
						std::string transacType = ahistory[j].getDesc();
						if (transacType == "id")
						{
							std::cout << "Initial deposit" << std::endl;
						}
						else if (transacType == "d")
						{
							std::cout << "Deposit" << std::endl;
						}
						else
						{
							std::cout << "Withdraw" << std::endl;
						}
						std::cout << "Time:" + ahistory[j].getTimeStamp() << std::endl;
						std::cout << "Value:" + ahistory[j].getValue() << std::endl;
					}
				}
			}
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

