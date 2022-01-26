#include <iostream>
#include "transaction.h"



void Transaction::setDesc(int d)   //Setting desc
{
	desc = d;
}
int Transaction::getDesc()    //Getting desc
{
	return desc;
}

void Transaction::setTimeStamp(std::string ts)   //Setting timestamp
{
	timestamp = ts;
}
std::string Transaction::getTimeStamp()    //Getting timestamp
{
	return timestamp;
}

void Transaction::setValue(double v)   //Setting value
{
	value = v;
}
double Transaction::getValue()    //Getting value
{
	return value;
}

void Transaction::toString()
{
	if (desc == 1)
	{
		std::cout << "- " << "Initial deposit " << value << " pounds, Date: " << timestamp << std::endl;
	}
	else if (desc == 2)
	{
		std::cout << "- " << "Deposit " << value << " pounds, Date: " << timestamp << std::endl;
	}
	else
	{
		std::cout << "- " << "Withdrawal " << value << " pounds, Date: " << timestamp << std::endl;
	}
	
}

