#include <iostream>
#ifndef Transaction_h
#define Transaction_h

class Transaction
{
protected:
	std::string desc;
	std::string timestamp;
	std::string value;

public:
	void setDesc(std::string d);   //Setting desc

	std::string getDesc();    //Getting desc

	void setTimeStamp(std::string ts);   //Setting timestamp

	std::string getTimeStamp();    //Getting timestamp

	void setValue(std::string v);   //Setting value

	std::string getValue();    //Getting value

	void toString();

};

#endif

