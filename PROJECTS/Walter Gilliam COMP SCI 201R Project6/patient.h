#pragma once
#include <string>
using namespace std;

struct patient
{
	patient();
	patient(string fname, string lname, int ssNum);
	bool operator==(const patient rhs);

	string firstName;
	string lastName;
	int SSN;
};