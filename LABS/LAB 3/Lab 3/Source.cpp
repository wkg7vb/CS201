#include <iostream>
#include <string>
#include "checkingmodule.h"
#include <iomanip>
using namespace std;

int main()
{
	int creditScore;
	float account = 0.00, amount, interestRate, loanMonths, loanAmount;
	bool keepusing = true;

	while (keepusing)
	{
		switch (MainMenu())
		{
		case 'D':
			{
				amount = GetValue("How much would you like to deposit?");
				deposit(account, amount);
				OutputAccount(account);
				break;
			}
		case 'W':
			{
				amount = GetValue("How much would you like to withdrawl?", account);
				Withdraw(account, amount);
				OutputAccount(account);
				break;
			}
		case 'L':
			{
				creditScore = GetCreditRating();
				interestRate = GetInterestRate(creditScore);
				loanMonths = GetLoanMonths();
				amount = GetValue("What size loan would you like to take out?");
				loanAmount = CalculateLoanAmount(amount, interestRate, loanMonths);
				cout << endl
					<< "Interest Rate: " << fixed << setprecision(2) << interestRate << endl
					<< "Principle: " << amount << endl
					<< "Months: " << loanMonths << endl
					<< "Your total loan amount is " << loanAmount << endl << endl;
				break;
			}
		case 'Q':
			{
				keepusing = false;
				break;
			}
		}
	}
}