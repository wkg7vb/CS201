#include "patient.h"
using namespace std;

patient::patient() 
{
	firstName = "";
	lastName = "";
	SSN = -1;
}

patient::patient(string fname, string lname, int ssNum)
{
	firstName = fname;
	lastName = lname;
	SSN = ssNum;
}

bool patient::operator==(const patient rhs)
{
	if (this->firstName == rhs.firstName)
	{
		if (this->lastName == rhs.lastName)
		{
			if (this->SSN == rhs.SSN)
			{
				return true;
			}
		}
	}
	else
	{
		return false;
	}
}