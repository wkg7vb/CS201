#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Media
{
	public:
		Media();
		Media(string id, string name, int length);
		string getID();
		string getAccName();
		int getLength();
		void setID(string id);
		void setAccName(string name);
		void setLength(int length);
		virtual void ReadData(istream& inSS);
		virtual void WriteData(ostream& outSS);
		virtual string getType() const = 0;

	protected:
		string identifier;
		string accountName;
		int lengthSec;
};