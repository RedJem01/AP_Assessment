#include <iostream>
#include "transaction.h"

using namespace T;
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

void Transaction::setValue(std::string v)   //Setting value
{
	value = v;
}
std::string Transaction::getValue()    //Getting value
{
	return value;
}

void Transaction::toString()
{
	std::cout << "1" << std::endl;
}

