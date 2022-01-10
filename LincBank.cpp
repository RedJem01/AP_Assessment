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
	int index = -1;

	std::cout << "~~~ Welcome to LincBank! ~~~" << std::endl;

	while (userCommand != "exit")
	{
		try
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
				//Checking if the amount value has only 2 or less decimal spaces
				std::vector<char> decimalCheck;
				bool pointCheck = false;

				//Looping through the string
				for (char c : parameters[2])
				{
					//If there is a decimal space
					if (pointCheck == true)
					{
						//Add all numbers after decimal to the list
						decimalCheck.emplace_back(c);
					}
					//Setting the bool value
					if (c == '.')
					{
						pointCheck = true;
					}
				}

				if (decimalCheck.size() > 2)
				{
					std::cout << "Please input a decimal with only 2 decimal spaces" << std::endl;
					continue;
				}

				std::string type;

				//If current account
				if (parameters[1] == "1")
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

					//If the amount is less than 0
					if (stoi(parameters[2]) < 0)
					{
						std::cout << "Please enter a number above or equal to 0." << std::endl;
						continue;
					}

					type = "c";

					//Opening new current account
					Account* c = new Current();
					
					c->open(type, c, openedAccounts, index, stoi(parameters[2]));
				
					std::cout << "A current account has been opened with a balance of " <<parameters[2] << " pounds." << std::endl;
				}
				//If savings account
				else if (parameters[1] == "2")
				{
					//If the amount is less than 0
					if (stoi(parameters[2]) < 0)
					{
						std::cout << "Please enter a number above or equal to 0." << std::endl;
						continue;
					}

					type = "s";

					//Open new savings account
					Account* s = new Savings();
					
					s->open(type, s, openedAccounts, index, stoi(parameters[2]));

					std::cout << "A savings account has been opened with an initial deposit of " << parameters[2] << " pounds." << std::endl;
				}
				//If ISA account
				else if (parameters[1] == "3")
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

					if (stoi(parameters[2]) < 1000)
					{
						std::cout << "That is not over 1000 pounds. Please input an amount over 1000 pounds." << std::endl;
						continue;
					}

					type = "i";

					//Opening new ISa account through savings
					Account* i = new Savings();

					i->open(type, i, openedAccounts, index, stoi(parameters[2]));

					std::cout << "An ISA savings account has been opened with an initial deposit of " << parameters[2] << " pounds." << std::endl;
				}
				//If not 1, 2 or 3
				else
				{
					std::cout << "Please only input 1, 2 or 3." << std::endl;
				}
			}
			else if (command.compare("view") == 0)
			{

				//Display an account according to an index (starting from 1)
				int viewIndex = stoi(parameters[1]) + 1;
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
						std::cout << "Balance of account: " << openedAccounts[i]->getBalance() << " pounds" << std::endl;
						std::cout << "Transactions: " << std::endl;
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
							std::cout << "Value: " << ahistory[j]->getValue() << " pounds" << std::endl;
						}
					}
				}
			}
			else if (command.compare("withdraw") == 0)
			{
				//Checking if the amount value has only 2 or less decimal spaces
				std::vector<char> decimalCheck;
				bool pointCheck = false;

				//Looping through the string
				for (char c : parameters[2])
				{
					//If there is a decimal space
					if (pointCheck == true)
					{
						//Add all numbers after decimal to the list
						decimalCheck.emplace_back(c);
					}
					//Setting the bool value
					if (c == '.')
					{
						pointCheck = true;
					}
				}

				if (decimalCheck.size() > 2)
				{
					std::cout << "Please input a decimal with only 2 decimal spaces" << std::endl;
					continue;
				}
				//Allow user to withdraw funds from an account
				int count = 0;

				int withIndex = stoi(parameters[1]) - 1;

				//Finding if the account index is in the list
				for (int i = 0; i < openedAccounts.size(); i++)
				{
					//If it is in the list
					if (withIndex == openedAccounts[i]->getIndex())
					{
						//If amount is negative
						if (stoi(parameters[2]) < 0)
						{
							std::cout << "Please input a positive number." << std::endl;
						}
						//If amount is positive
						else
						{
							if (openedAccounts[i]->getType() == "c")
							{
								Current* c = new Current();

								//If amount is more than balance 
								if (openedAccounts[i]->getBalance() < stoi(parameters[2]))
								{
									std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
								}
								//If amount is less than balance
								else
								{
									c->withdraw(openedAccounts, i, stoi(parameters[2]));
									delete c;
									std::cout << parameters[2] << " pounds has been withdrawn from account " << parameters[1] << std::endl;
								}
							}
							else
							{
								Savings* s = new Savings();

								//If amount is more than balance 
								if (openedAccounts[i]->getBalance() < stoi(parameters[2]))
								{
									std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
								}
								//If amount is less than balance
								else
								{
									s->withdraw(openedAccounts, i, stoi(parameters[2]));
									delete s;
									std::cout << parameters[2] << " pounds has been withdrawn from account " << parameters[1] << std::endl;
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
			else if (command.compare("deposit") == 0)
			{
				//Checking if the amount value has only 2 or less decimal spaces
				std::vector<char> decimalCheck;
				bool pointCheck = false;

				//Looping through the string
				for (char c : parameters[2])
				{
					//If there is a decimal space
					if (pointCheck == true)
					{
						//Add all numbers after decimal to the list
						decimalCheck.emplace_back(c);
					}
					//Setting the bool value
					if (c == '.')
					{
						pointCheck = true;
					}
				}

				if (decimalCheck.size() > 2)
				{
					std::cout << "Please input a decimal with only 2 decimal spaces" << std::endl;
					continue;
				}
				//Allow user to deposit funds into an account
				int count = 0;
				int withIndex = stoi(parameters[1]) - 1;

				//Finding if the account index is in the list
				for (int i = 0; i < openedAccounts.size(); i++)
				{
					//If it is in the list
					if (withIndex == openedAccounts[i]->getIndex())
					{
						if (stoi(parameters[2]) > 0)
						{
							if (openedAccounts[i]->getType() == "c")
							{
								Current* c = new Current();
								c->deposit(openedAccounts, i, stoi(parameters[2]));
								delete c;
								std::cout << parameters[2] << " pounds has been deposited into account " << parameters[1] << std::endl;
							}
							else
							{
								Savings* s = new Savings();
								s->deposit(openedAccounts, i, stoi(parameters[2]));
								delete s;
								std::cout << parameters[2] << " pounds has been deposited into account " << parameters[1] << std::endl;
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
			else if (command.compare("transfer") == 0)
			{
				//Checking if the amount value has only 2 or less decimal spaces
				std::vector<char> decimalCheck;
				bool pointCheck = false;

				//Looping through the string
				for (char c : parameters[3])
				{
					//If there is a decimal space
					if (pointCheck == true)
					{
						//Add all numbers after decimal to the list
						decimalCheck.emplace_back(c);
					}
					//Setting the bool value
					if (c == '.')
					{
						pointCheck = true;
					}
				}

				if (decimalCheck.size() > 2)
				{
					std::cout << "Please input a decimal with only 2 decimal spaces" << std::endl;
					continue;
				}
				//Allow user to transfer funds between accounts
				int count = 0;
				int count2 = 0;

				int index = stoi(parameters[1]) - 1;
				int index2 = stoi(parameters[2]) - 1;

				//Finding if the account index is in the list
				for (int i = 0; i < openedAccounts.size(); i++)
				{
					//If it is in the list
					if (index == openedAccounts[i]->getIndex())
					{
						//Finding if the 2nd account index is in the list
						for (int j = 0; j < openedAccounts.size(); j++)
						{
							//If it is in the list
							if (index2 == openedAccounts[j]->getIndex())
							{
								//If amount is negative or 0
								if (stoi(parameters[3]) <= 0)
								{
									std::cout << "Please input a number above 0." << std::endl;
								}
								//If amount is above 0;
								else
								{
									//Withdrawing

									//If account type is current
									if (openedAccounts[i]->getType() == "c")
									{
										Current* c = new Current();

										//If amount is more than balance 
										if (openedAccounts[i]->getBalance() < stoi(parameters[3]))
										{
											std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
										}
										//If amount is less than balance
										else
										{
											c->withdraw(openedAccounts, i, stoi(parameters[3]));
											delete c;
											std::cout << parameters[3] << " pounds has been withdrawn from account " << parameters[1] << std::endl;
										}
									}
									//If account type is savings
									else
									{
										Savings* s = new Savings();

										//If amount is more than balance 
										if (openedAccounts[i]->getBalance() < stoi(parameters[3]))
										{
											std::cout << "The amount you want to withdraw is more than the amount in your account plus your overdraft. Please choose a smaller amount." << std::endl;
										}
										//If amount is less than balance
										else
										{
											s->withdraw(openedAccounts, i, stoi(parameters[3]));
											delete s;
											std::cout << parameters[3] << " pounds has been withdrawn from account " << parameters[1] << std::endl;
										}
									}

									//Depositing

									//If account type is current
									if (openedAccounts[j]->getType() == "c")
									{
										Current* c = new Current();
										c->deposit(openedAccounts, j, stoi(parameters[3]));
										delete c;
										std::cout << parameters[3] << " pounds has been deposited into account " << parameters[2] << std::endl;
									}
									//If account type is savings
									else
									{
										Savings* s = new Savings();
										s->deposit(openedAccounts, j, stoi(parameters[3]));
										delete s;
										std::cout << parameters[3] << " pounds has been deposited into account " << parameters[2] << std::endl;
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
						count2 += 1;
						//If gone through list and no matching index
						if (count2 == openedAccounts.size())
						{
							std::cout << "The index you inputted has no account attatched to it. Please try again." << std::endl;
						}
					}
				}
			}
			else if (command.compare("project") == 0)
			{
				//Compute compound interest t years into the future
				int count = 0;
				double interestRate;

				int index = stoi(parameters[1]) - 1;

				//Finding if the account index is in the list
				for (int i = 0; i < openedAccounts.size(); i++)
				{
					//If it is in the list
					if (index == openedAccounts[i]->getIndex())
					{
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
						double finalAmount = s->computeInterest(interestRate, openedAccounts[i]->getBalance(), stoi(parameters[2]));
						delete s;
						std::cout << "Your balance in " << parameters[2] << " years will be " << finalAmount << " pounds." << std::endl;
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
			else if (command.compare("search") == 0)
			{
				//allow users to search their account history for a transaction
				int count = 0;
				int count2 = 0;
				int searchIndex = stoi(parameters[1]) - 1;

				//Finding if the account index is in the list
				for (int i = 0; i < openedAccounts.size(); i++)
				{
					//If it is in the list
					if (searchIndex == openedAccounts[i]->getIndex())
					{
						std::vector<Transaction*> history = openedAccounts[i]->getHistory();
						for (int j = 0; j < history.size(); j++)
						{
							if (history[j]->getValue() == stoi(parameters[2]))
							{
								if (history[j]->getDesc() == "id")
								{
									std::cout << "Initial deposit" << std::endl;
								}
								else if (history[j]->getDesc() == "d")
								{
									std::cout << "Deposit" << std::endl;
								}
								else
								{
									std::cout << "Withdraw" << std::endl;
								}
								std::cout << "Value: " << history[j]->getValue() << " pounds" << std::endl;
								std::cout << "Date and time: " << history[j]->getTimeStamp() << std::endl;
 							}
							else
							{
								count += 1;
								//If gone through and there is no matching value
								if (count == history.size())
								{
									std::cout << "There is no transaction with that value." << std::endl;
								}
							}
						}
					}
					else
					{
						count2 += 1;
						//If gone through list and no matching index
						if (count2 == openedAccounts.size())
						{
							std::cout << "The index you inputted has no account attatched to it. Please try again." << std::endl;
						}
					}
				}
			}
		}
		catch (std::invalid_argument)
		{
			std::cout << "One of your inputs is wrong. If it is a money input it has to be a number with a decimal space of 0-2. If it is any other number it needs to have no decimal spaces." << std::endl;
			continue;
		}
	}

	std::cout << "Press any key to quit...";
	std::getchar();
}

