#include <iostream>
#include "transaction.h"

//Transaction::Transaction(std::string a, std::string b, double c)
//{
//	desc = a;
//	timestamp = b;
//	value = c;
//}

void Transaction::setDesc(std::string d)   //Setting desc
{
	desc = d;
}
std::string Transaction::getDesc()    //Getting desc
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
	std::cout << "-" << desc << value << "pounds, Date: " << timestamp << std::endl;
}

