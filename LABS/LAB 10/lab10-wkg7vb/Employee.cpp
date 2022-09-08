// Your name	Walter Gilliam
// Today's date	11/16/2021
// 

#include <string>
#include "Employee.h"
using namespace std;

// Constructor
Employee::Employee(int id, string myName)
{
	employeeID = id;
	name = myName;
	balance = 0.00;
	payRate = 10.00;
	employed = true;
}

// Getter to return the employee ID
int Employee::getEmployeeID()
{
	return(employeeID);
}

// Getter to return the current pay rate
double Employee::getPayRate()
{
	return(payRate);
}

// Getter to return the current amount of pay earned
double Employee::getBalance()
{
	return(balance);
}

// Getter to get Employee's name
string Employee::getName()
{
	return(name);
}

// Function to give the raise. It takes in a percent in whole numbers 
// (ex: 5 for 5%)
void Employee::giveRaise(int rate)
{
	payRate += payRate * (rate / 100.00);
}

// Pays the employee
void Employee::pay()
{
	balance += payRate; //this is gonna need changed, just wanted something there.
}

// Fires the Employee
void Employee::fire()
{
	employed = false;
	payRate = 0;
}

// Returns if the Employee is currently employed
bool Employee::isEmployed()
{
	return(employed);
}