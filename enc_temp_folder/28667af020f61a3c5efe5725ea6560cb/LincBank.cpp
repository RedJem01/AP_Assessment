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
	std::vector <Account*> openedAccounts;
	bool isaOpened = false;
	int index = 0;

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
			bool loop2 = true;

			//Input verification
			while (loop == true)   
			{
				double input;
				std::string accountChoice;
				std::cout << "What kind of account would you like to open? Please input 1 for a current account, 2 for a regular savings acount or 3 for an ISA savings account." << std::endl;
				
				//User input
				std::getline(std::cin, accountChoice);  

				//If current account
				if (accountChoice == "1")   
				{
					//Looping through the list of opened accounts
					for (int i = 0; i < openedAccounts.size(); i++)
					{
						//If any are current accounts
						if (openedAccounts[i]->getType() == "c")
						{
							std::cout << "A current account already exists." << std::endl;
							continue;
						}
					}
					//Opening new current account
					Account* c = new Current();   

					//Setting index
					index += 1;
					c->setIndex(index);

					//Setting type
					c->setType("c");

					//Input verification
					while (loop2 == true)
					{
						try
						{
							//User input
							std::cout << "How much would you like to open this account with?" << std::endl;
							std::cin >> input;
							if (input < 0)
							{
								std::cout << "Please enter a number above or equal to 0." << std::endl;
							}
							else
							{
								loop2 = false;
							}
						}
						catch (std::invalid_argument)
						{
							std::cout << "Please enter a number with 0-2 decimal spaces." << std::endl;
						}
					}

					//Setting balance
					c->setBalance(input); 

					//Making a new transaction object
					Transaction* t = new Transaction();

					//Finding current date and time
					time_t now = time(0);
					char* dt = ctime(&now);

					//Setting attributes for transaction
					t->setDesc("id");
					t->setTimeStamp(dt);
					t->setValue(input);

					//Adding transaction details to history
					c->setHistory(t);

					//Putting object into accounts list
					openedAccounts.emplace_back(c);  

					//Right input so end loop
					loop = false;
				}
				//If savings account
				else if (accountChoice == "2")   
				{
					//Open new savings account
					Savings* s = new Savings();  
					
					//A new account has been opened so index increases by 1
					index += 1;

					//Setting attributes
					s->setIndex(index);
					s->setType("s");
					s->setInterestRate(0.85);  
					s->setIsa(false);  

					//Input verification
					while (loop2 = true)
					{
						try
						{
							//User input
							std::cout << "How much would you like to open this account with?" << std::endl;
							std::cin >> input;
							if (input < 0)
							{
								std::cout << "Please enter a number above or equal to 0." << std::endl;
							}
							else
							{
								loop2 = false;
							}
						}
						catch (std::invalid_argument)
						{
							std::cout << "Please enter a number with 0-2 decimal spaces." << std::endl;
						}
					}

					//Setting balance
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

					s->setHistory(t);

					//Putting object into accounts list
					openedAccounts.emplace_back(s);

					//Right input so end loop
					loop = false;
				}
				//If ISA account
				else if (accountChoice == "3")  
				{
					//Looping through the list of opened accounts
					for (int i = 0; i < openedAccounts.size(); i++)
					{
						//If any are current accounts
						if (openedAccounts[i]->getType() == "i")
						{
							std::cout << "An ISA account already exists." << std::endl;
							continue;
						}
					}

					//Opening new ISa account through savings
					Savings* i = new Savings();   
					
					//Seting index
					index += 1;
					i->setIndex(index);
					i->setType("i");

					i->setInterestRate(1.15); 

					i->setIsa(true);

					//Check opening balance is over £1000
					while (loop2 = true)  
					{ 
						try
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
						catch (std::invalid_argument)
						{
							std::cout << "Please input a number with 0-2 decimal spaces." << std::endl;
						}
					}

					//Setting balance
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

					i->setHistory(t);

					openedAccounts.emplace_back(i);
					loop = false;
				}
				//If not 1, 2 or 3
				else
				{
					std::cout << "Please only input 1, 2 or 3." << std::endl;
				}
			}
		}
		else if (command.compare("view") == 0)
		{
			bool loop = true;
			while (loop == true)
			{
				try
				{
					//Display an account according to an index (starting from 1)
					std::cout << "Please provide an index for the account you want to view (Starting from 1). If you do not know the index just press enter and all the accounts will come up." << std::endl;
					int ViewIndex;
					std::cin >> ViewIndex;
					int viewIndex = ViewIndex - 1;
					int count = 0;

					//looping through account list and finding the index
					for (int i = 0; i < openedAccounts.size(); i++)
					{
						if (openedAccounts[i]->getIndex() == viewIndex)
						{
							std::string accountType = openedAccounts[i]->getType();
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
							std::cout << "Balance of account:" << openedAccounts[i]->getBalance() << std::endl;
							std::cout << "Transactions:" << std::endl;
							std::vector<Transaction*> ahistory = openedAccounts[i]->getHistory();

							//Looping through the transactions of an account and output all info from each transaction
							for (int j = 0; j < ahistory.size(); j++)
							{
								std::string transacType = ahistory[j]->getDesc();
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
								std::cout << "Time:" << ahistory[j]->getTimeStamp() << std::endl;
								std::cout << "Value:" << ahistory[j]->getValue() << std::endl;
							}
						}
						else
						{
							count += 1;
						}
					}

					//If the input was not an index that exists then display all of the accounts
					if (count = openedAccounts.size())
					{
						//Loop through account list and output all info from each account
						for (int i = 0; i < openedAccounts.size(); i++)
						{
							std::string accountType = openedAccounts[i]->getType();
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
							std::cout << "Balance of account:" << openedAccounts[i]->getBalance() << std::endl;
							std::cout << "Transactions:" << std::endl;
							std::vector<Transaction*> ahistory = openedAccounts[i]->getHistory();

							//Looping through the transactions of an account and ouput all info from each transaction
							for (int j = 0; j < ahistory.size(); j++)
							{
								std::string transacType = ahistory[j]->getDesc();
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
									std::cout << "Withdrawal" << std::endl;
								}
								std::cout << "Time:" << ahistory[j]->getTimeStamp() << std::endl;
								std::cout << "Value:" << ahistory[j]->getValue() << std::endl;
							}
						}
					}
				}
				catch (std::invalid_argument)
				{
					std::cout << "Please input a number with 0 decimal spaces." << std::endl;
				}
			}
		}
		else if (command.compare("withdraw") == 0)
		{
			//Allow user to withdraw funds from an account
			bool loop = true;
			int count = 0;
			int place;

			//Input verification 
			while (loop == true)
			{
				try
				{
					//Inputting the account index
					std::cout << "Please input the index for the account you want to withdraw from (Starting from 1)." << std::endl;
					int WithIndex;
					std::cin >> WithIndex;
					int withIndex = WithIndex - 1;

					//Finding if the account index is in the list
					for (int i = 0; i < openedAccounts.size(); i++)
					{
						//If it is in the list
						if (withIndex == openedAccounts[i]->getIndex())
						{
							//Save the position and end loop
							place = i;
							//Inputting amount to withdraw
							std::cout << "Please input the amount you want to withdraw." << std::endl;
							int amount;
							std::cin >> amount;

							//If amount is negative
							if (amount < 0)
							{
								std::cout << "Please input a positive number." << std::endl;
							}
							//If amount is positive
							else
							{
								if (openedAccounts[place]->getType() == "c")
								{
									Current* c = new Current();

									//If amount is more than balance 
									if (openedAccounts[place]->getBalance() < amount)
									{
										std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
									}
									//If amount is less than balance
									else
									{
										c->withdraw(openedAccounts, place, amount);
										loop = false;
									}

								}
								else
								{
									Savings* sa = new Savings();

									//If amount is more than balance 
									if (openedAccounts[place]->getBalance() < amount)
									{
										std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
									}
									//If amount is less than balance
									else
									{
										sa->withdraw(openedAccounts, place, amount);
										loop = false;
									}
								}
							}
						}
						else
						{
							count += 1;
							//If gone through list and no matching index
							if (count == openedAccounts.size())
							{
								std::cout << "The index you inputted has no account attatched to it. Please try again." << std::endl;
							}
						}
					}
				}
				catch (std::invalid_argument)
				{
					std::cout << "Please enter a number with no decimal spaces." << std::endl;
				}
			}
		}
		else if (command.compare("deposit") == 0)
		{
			//Allow user to deposit funds into an account
			int place;
			int count = 0;
			bool loop = true;

			//Input verification 
			while (loop == true)
			{
				try
				{
					//Inputting the account index
					std::cout << "Please input the index for the account you want to withdraw from (Starting from 1)." << std::endl;
					int WithIndex;
					std::cin >> WithIndex;
					int withIndex = WithIndex - 1;

					//Finding if the account index is in the list
					for (int i = 0; i < openedAccounts.size(); i++)
					{
						//If it is in the list
						if (withIndex == openedAccounts[i]->getIndex())
						{
							//Save the position and end loop
							place = i;
							//Inputting amount to deposit
							std::cout << "Please input the amount you would like to deposit." << std::endl;
							int amount;
							std::cin >> amount;
							if (amount > 0)
							{
								if (openedAccounts[place]->getType() == "c")
								{
									Current* ca = new Current();
									ca->deposit(openedAccounts, place, amount);
									loop = false;
								}
								else
								{
									Savings* sa = new Savings();
									sa->deposit(openedAccounts, place, amount);
									loop = false;
								}
							}
							else
							{
								std::cout << "Please input an amount above 0." << std::endl;
							}
						}
						else
						{
							count += 1;
							//If gone through list and no matching index
							if (count == openedAccounts.size())
							{
								std::cout << "The index you inputted has no account attatched to it. Please try again." << std::endl;
							}
						}
					}
				}
				catch (std::invalid_argument)
				{
					std::cout << "Please input a number without decimal spaces." << std::endl;
				}
			}
		}
		else if (command.compare("transfer") == 0)
		{
			//Allow user to transfer funds between accounts
			bool loop = true;
			bool loop2 = true;
			bool loop3 = true;
			int place2;
			int place;
			int count = 0;

			//Input verification 
			while (loop == true)
			{
				try
				{
					//Inputting the account index
					std::cout << "Please input the index for the account you want to transfer from (Starting from 1)." << std::endl;
					int Index;
					std::cin >> Index;
					int index = Index - 1;

					//Finding if the account index is in the list
					for (int i = 0; i < openedAccounts.size(); i++)
					{
						//If it is in the list
						if (index == openedAccounts[i]->getIndex())
						{
							//Save the position and end loop
							place = i;

							//Inputting the 2nd account index
							std::cout << "Please input the index for the account you want to transfer to (Starting from 1)." << std::endl;
							int Index;
							std::cin >> Index;
							int index = Index - 1;

							//Finding if the 2nd account index is in the list
							for (int i = 0; i < openedAccounts.size(); i++)
							{
								//If it is in the list
								if (index == openedAccounts[i]->getIndex())
								{
									//Save the position and end loop
									place2 = i;

									//Inputting amount to transfer
									std::cout << "Please input the amount you would like to transfer." << std::endl;
									int amount;
									std::cin >> amount;

									//If amount is negative or 0
									if (amount <= 0)
									{
										std::cout << "Please input a number above 0." << std::endl;
									}
									//If amount is above 0;
									else
									{
										//If account type is current
										if (openedAccounts[place]->getType() == "c")
										{
											Current* c = new Current();

											//If amount is more than balance 
											if (openedAccounts[place]->getBalance() < amount)
											{
												std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
											}
											//If amount is less than balance
											else
											{
												c->withdraw(openedAccounts, place, amount);
											}
										}
										//If account type is savings
										else
										{
											Savings* s = new Savings();

											//If amount is more than balance 
											if (openedAccounts[place]->getBalance() < amount)
											{
												std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
											}
											//If amount is less than balance
											else
											{
												s->withdraw(openedAccounts, place, amount);
											}
										}

										//If account type is current
										if (openedAccounts[place2]->getType() == "c")
										{
											Current* c = new Current();
											c->deposit(openedAccounts, place2, amount);
											loop = false;
										}
										//If account type is savings
										else
										{
											Savings* s = new Savings();
											s->deposit(openedAccounts, place2, amount);
											loop = false;
										}
									}
								}
								//If it isn't in the list
								else
								{
									count += 1;
									//If gone through list and no matching index
									if (count == openedAccounts.size())
									{
										std::cout << "The index you inputted has no account attatched to it. Please try again." << std::endl;
									}
								}
							}
						}
						else
						{
							count += 1;
							//If gone through list and no matching index
							if (count == openedAccounts.size())
							{
								std::cout << "The index you inputted has no account attatched to it. Please try again." << std::endl;
							}
						}
					}
				}
				catch (std::invalid_argument)
				{
					std::cout << "Please input a number with no decimal spaces." << std::endl;
				}
			}
		}
		else if (command.compare("project") == 0)
		{
			//Compute compound interest t years into the future
			bool loop = true;
			bool loop2 = true;
			int count = 0;
			double interestRate;

			while (loop == true)
			{
				try
				{
					std::cout << "Please enter the index (starting from 1) of the account you would ike to find the interest for." << std::endl;
					int Index;
					std::cin >> Index;
					int index = Index - 1;

					//Finding if the account index is in the list
					for (int i = 0; i < openedAccounts.size(); i++)
					{
						//If it is in the list
						if (index == openedAccounts[i]->getIndex())
						{
							//Input verification for years
							while (loop2 == true)
							{
								try
								{
									//Inputting no of years
									std::cout << "Please input the amount of years you would like to project the interest earned on a savings account for." << std::endl;
									double years;
									std::cin >> years;

									Savings* s = new Savings();
									if (openedAccounts[i]->getType() == "s")
									{
										interestRate = 0.85;
									}
									else if (openedAccounts[i]->getType() == "c")
									{
										std::cout << "The account needs to be a savings account" << std::endl;
										continue;
									}
									else 
									{
										interestRate = 1.15;
									}

									//Calling the computeInterest function
									double finalAmount = s->computeInterest(interestRate, openedAccounts[i]->getBalance(), years);
									std::cout << "Your balance in " << years << "years will be " << finalAmount << std::endl;
									loop2 = false;
								}
								catch (std::invalid_argument)
								{
									std::cout << "Please input a number with 0-2 decimal spaces." << std::endl;
									loop2 = true;
								}
							}
							loop = false;
						}
						else
						{
							count += 1;

							//If gone through list and no matching index
							if (count == openedAccounts.size())
							{
								std::cout << "The index you inputted has no account attatched to it. Please try again." << std::endl;
							}
						}
					}
				}
				catch (std::invalid_argument)
				{
					std::cout << "Please input a number with no decimal points." << std::endl;
				}
			}
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

