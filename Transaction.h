#include <iostream>
#ifndef Transaction_h
#define Transaction_h

class Transaction
{
protected:
	std::string desc;
	std::string timestamp;
	double value;

public:
	Transaction();
	~Transaction();

	void setDesc(std::string d);   //Setting desc

	std::string getDesc();    //Getting desc

	void setTimeStamp(std::string ts);   //Setting timestamp

	std::string getTimeStamp();    //Getting timestamp

	void setValue(double v);   //Setting value

	double getValue();    //Getting value

	void toString();

};

#endif

