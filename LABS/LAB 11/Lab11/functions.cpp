#include "functions.h"
using namespace std;

long long factorial_r(long value)
{
	long total = value;

	if (value <= 1)
	{
		return total;
	}
	else
	{
		total *= factorial_r(value - 1);
	}
}

int fibonacci_r(int n)
{

	if (n <= 1)
	{
		return n;
	}
	else
	{
		return (fibonacci_r(n - 1) + fibonacci_r(n - 2));
	}
}

bool is_prime_r(int value, int n)
{
	double temp = value;
	double root = sqrt(temp);

	if (n > root)
	{
		return true;
	}
	else if (value % n == 0)
	{
		return false;
	}
	else
	{
		is_prime_r(value, n + 1);
	}
}

int sum_r(int list[], int list_size)
{
	if (list_size <= 0)
	{
		return 0;
	}
	else
	{
		return (list[list_size - 1] + sum_r(list, (list_size - 1)));
	}
}

void output_reverse_list_r(int list[], int list_size)
{
	if (list_size <= 0)
	{

	}
	else
	{
		cout << list[list_size - 1] << " ";
		output_reverse_list_r(list, (list_size - 1));
		cout << endl;
	}
}