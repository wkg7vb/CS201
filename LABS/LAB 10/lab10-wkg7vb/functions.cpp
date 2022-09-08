#include <vector>
#include <iostream>
#include "functions.h"
#include "Employee.h"

//returns index of employee with id number, given an id number and the roster.
int find(const int& idNum, vector<Employee> roster)
{
	//linear search, short lists, and also i don't want to sort everytime we add new employees, im just lazy
	for (unsigned int i = 0; i < roster.size(); ++i)
	{
		if (roster.at(i).getEmployeeID() == idNum)
		{
			return(i);
		}
		if (i == roster.size() - 1)
		{
			cout << "Not Found" << endl;
		}
	}
	return(-1);
}