#include <iostream>
#include <string>
using namespace std;

void deposit(float& account, float amount);
char MainMenu();
float GetValue(string ask4input);
float GetValue(string ask4input, float limit);
float GetInterestRate(int creditScore);
void Withdraw(float& account, float amount);
int GetLoanMonths();
int GetCreditRating();
float CalculateLoanAmount(float principle, float rate, int months);
void OutputAccount(float accountAmount);