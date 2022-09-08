#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Employee.h"
#include "functions.h"
using namespace std;

int main()
{
	vector<Employee> roster;
	string command;
	string fName, lName, tempName;
	int tempIDN;
	int tempRate;

	ifstream inFS;
	ofstream outFS;

	inFS.open("input.txt");

	while (!inFS.eof())
	{
		inFS >> command;
		
		if (command == "NEW")
		{
			inFS >> tempIDN >> fName >> lName;
			tempName = fName + " " + lName;
			roster.push_back(Employee(tempIDN, tempName));
		}
		else if (command == "RAISE")
		{
			inFS >> tempIDN >> tempRate;
			roster.at(find(tempIDN, roster)).giveRaise(tempRate);
		}
		else if (command == "PAY")
		{
			for (unsigned int i = 0; i < roster.size(); ++i)
			{
				roster.at(i).pay();
			}
		}
		else if (command == "FIRE")
		{
			inFS >> tempIDN;
			roster.at(find(tempIDN, roster)).fire();
		}
	}

	inFS.close();
	outFS.open("output.txt");

	for (unsigned int i = 0; i < roster.size(); ++i)
	{
		outFS << roster.at(i).getName() << ", ID Number " << roster.at(i).getEmployeeID() << ":" << endl;
		if (roster.at(i).isEmployed())
		{
			outFS << "Current pay rate: $" << fixed << setprecision(2) << roster.at(i).getPayRate() << endl;
		}
		else
		{
			outFS << "Not employed with the company" << endl;
		}
		outFS << "Pay earned to date: $" << fixed << setprecision(2) << roster.at(i).getBalance() << endl << endl;
	}

	outFS.close();

	return(0);
}