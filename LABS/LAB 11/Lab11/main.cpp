#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
	int input;
	const int numValues = 5;
	int list[numValues];

	cout << "Enter an integer" << endl;
	cin >> input;
	cout << input << "! = " << factorial_r(input) << endl;
	cout << "fibonacci(" << input << ") = " << fibonacci_r(input) << endl;

	if (is_prime_r(input, 2))
	{
		cout << input << " is a prime number" << endl;
	}
	else
	{
		cout << input << " is not a prime number" << endl;
	}

	cout << "Enter " << numValues << " numbers to put in an array" << endl;
	for (int i = 0; i < numValues; ++i)
	{
		cout << "Enter value for index " << i << endl;
		cin >> list[i];
	}
	
	cout << "The sum of the " << numValues << " numbers you entered is " << sum_r(list, numValues) << endl;
	cout << "The reverse order of the " << numValues << " numbers you entered is ";
	output_reverse_list_r(list, numValues);
	
	return 0;
}