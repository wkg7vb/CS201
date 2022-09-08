#include "Header.h"
using namespace std;

double GetMiles()
{
	double miles;
	cout << "Input number of miles (use a decimal point)" << endl;
	cin >> miles;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		throw runtime_error("Invalid input received, you must enter a decimal number. ");
	}

	if (miles <= 0)
	{
		throw runtime_error("Invalid value.");
	}

	return miles;
}

double GetGallons()
{
	double gal;
	cout << "Input number of gallons (use a decimal point)" << endl;
	cin >> gal;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		throw runtime_error("Invalid input received, you must enter a decimal number. ");
	}

	if (gal <= 0)
	{
		throw runtime_error("Invalid value.");
	}

	return gal;
}

double GetMPG(vector <double> miles, vector <double> gallons)
{
	double totalM = 0;
	double totalG = 0;
	double MPG;
	if (miles.size() == 0 || gallons.size() == 0)
	{
		throw runtime_error("No values recorded, MPG is not a number.");
	}

	for (int i = 0; i < miles.size(); ++i)
	{
		totalM += miles.at(i);
	}
	for (int i = 0; i < gallons.size(); ++i)
	{
		totalG += gallons.at(i);
	}

	MPG = totalM / totalG;

	return MPG;
}

bool again()
{
	char input;
	cout << "Would you like to input another tank? (Y for yes and N for no)" << endl;
	cin >> input;

	switch (input)
	{
		case 'Y':
		case 'y':
		{
			return true;
		}
		case 'N':
		case 'n':
		{
			return false;
		}
		default:
		{
			cout << "Invalid input" << endl;
			again();
		}

	}
}