#include <iostream>
#ifndef Transaction_h
#define Transaction_h

class Transaction
{
protected:
	int desc;
	std::string timestamp;
	double value;

public:
	Transaction(int a, std::string b, double c) :desc(a), timestamp(b), value(c) {}

	void setDesc(int d);   //Setting desc

	int getDesc();    //Getting desc

	void setTimeStamp(std::string ts);   //Setting timestamp

	std::string getTimeStamp();    //Getting timestamp

	void setValue(double v);   //Setting value

	double getValue();    //Getting value

	void toString();
};

#endif

