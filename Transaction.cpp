#include <iostream>
#include "transaction.h"

class Transaction
{
	protected:
		std::string desc;
		std::string timestamp;
		std::string value;

	public:
		void setDesc(std::string d)   //Setting desc
		{
			desc = d;
		}
		std::string getDesc()    //Getting desc
		{
			return desc;
		}

		void setTimeStamp(std::string ts)   //Setting timestamp

		{
			timestamp = ts;
		}
		std::string getTimeStamp()    //Getting timestamp
		{
			return timestamp;
		}

		void setValue(std::string v)   //Setting value
		{
			value = v;
		}
		std::string getValue()    //Getting value
		{
			return value;
		}

		void toString()
		{

		}
};
