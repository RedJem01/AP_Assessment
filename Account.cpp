#include <iostream>
class Account
{

};

class InterestEarning
{

};

class Current : public Account
{

};

class Savings : public Account, public InterestEarning
{

};