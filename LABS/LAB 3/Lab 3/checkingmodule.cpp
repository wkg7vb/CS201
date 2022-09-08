#include <iostream>
#include <string>
#include <iomanip>
#include "checkingmodule.h"
using namespace std;

void deposit(float& account, float amount)
{
	account += amount;
}

char MainMenu()
{
	char choice;
	bool valid;

	do
	{
		cout << "Main Menu:" << endl
			<< "Select from the following options" << endl
			<< "(D)eposit" << endl
			<< "(W)ithdrawal" << endl
			<< "(L)oan" << endl
			<< "(Q)uit" << endl;
		cin >> choice;
		choice = toupper(choice);

		valid = true;

		if (choice != 'D' && choice != 'W' && choice != 'L' && choice != 'Q')
		{
			cout << endl 
				<< "Invalid input, please input D, W, L, or Q." << endl 
				<< endl;
			valid = false;
		}
	} while (!valid);

	cout << endl;

	return choice;
}

float GetValue(string ask4input)
{
	float input;
	bool valid;

	do 
	{
		cout << ask4input << endl;
		cin >> input;

		valid = true;

		if (input < 0)
		{
			cout << endl 
				<< "Invalid input, please input a number greater than 0." << endl 
				<< endl;
			valid = false;
		}
	} while (!valid);

	cout << endl;

	return input;
}

float GetValue(string ask4input, float limit)
{
	float input;
	bool valid;

	do
	{
		cout << ask4input << endl;
		cin >> input;

		valid = true;

		if (input < 0 || input > limit)
		{
			cout << endl 
				<< "Invalid input, please input a number greater than 0 and less than " 
				<< fixed << setprecision(2) << limit << "." << endl 
				<< endl;
			valid = false;
		}
	} while (!valid);

	cout << endl;

	return input;
}

float GetInterestRate(int creditScore)
{
	float interestRate;

	if (creditScore <= 500)
	{
		interestRate = 0.05;
	}
	else if (creditScore <= 700)
	{
		interestRate = 0.03;
	}
	else if (creditScore > 700)
	{
		interestRate = 0.01;
	}

	return interestRate;
}

void Withdraw(float& account, float amount)
{
	account -= amount;
}

int GetLoanMonths()
{
	int input;
	bool valid;

	do
	{
		cout << "How many months loan would you like?" << endl
			<< "Your options are 12, 24, 36 or 60." << endl;
		cin >> input;

		valid = true;

		if (input != 12 && input != 24 && input != 36 && input != 60)
		{
			cout << endl
				<< "Invalid input, please input 12, 24, 36, or 60." << endl
				<< endl;
			valid = false;
		}
	} while (!valid);

	cout << endl;

	return input;
}

int GetCreditRating()
{
	int input;
	bool valid;

	do
	{
		cout << "What is your credit rating?" << endl
			<< "Enter a number from 300 to 850." << endl;
		cin >> input;

		valid = true;

		if (input < 300 || input > 850)
		{
			cout << endl
				<< "Invalid input, please input a number from 300 to 850." << endl
				<< endl;
			valid = false;
		}
	} while (!valid);

	cout << endl;

	return input;
}

float CalculateLoanAmount(float principle, float rate, int months)
{
	float loanAmount = principle * pow((1 + (rate / 12)), (months / 12));

	return loanAmount;
}

void OutputAccount(float accountAmount)
{
	cout << "Your account contains:" << endl
		<< "$" << fixed << setprecision(2) << accountAmount << endl 
		<< endl;
}