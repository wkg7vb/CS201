#include "header.h"
using namespace std;

void Menu(bool & again)
{
	int input;

	cout << "Select from the following options" << endl
		<< "1: Output Electronics Supplies" << endl
		<< "2: Output Office Supplies" << endl
		<< "3: Output Supplies to File" << endl
		<< "4: Quit" << endl
		<< "(use numbers 1-4 to make your selection)" << endl;

	cin >> input;
	cout << endl;

	switch (input)
	{
		case 1:
		{
			OutputD('E');
			break;
		}
		case 2:
		{
			OutputD('O');
			break;
		}
		case 3:
		{
			cout << endl << "Processing Summary.txt ... ";
			OutputF();
			OutputF();
			cout << "Completed" << endl << endl;
			break;
		}
		case 4:
		{
			again = false;
			break;
		}
		default:
		{
			cout << "Invaid input. Please try again using a number 1-4." << endl;
			Menu(again);
			break;
		}
	}
}

void OutputD(char userDep)
{
	int quantity;
	double price;
	double totalValue = 0;
	char department, tempDS;
	string name, type;

	ifstream inFS;
	inFS.open("Office.txt");

	if (userDep == 'E')
	{
		type = "Electronics";
	}
	else if (userDep == 'O')
	{
		type = "Office";
	}

	cout << type << " Supplies Inventory" << endl << endl;
	cout << left << setw(15) << "Department" << setw(20) << "Name" << setw(15) << "Quanitiy" << setw(15) << "Price(each)" << setw(15) << "Price(total)" << endl;
	
	do
	{
		inFS >> department >> quantity >> name >> tempDS >> price;

		if (department == userDep && !inFS.eof())
		{
			cout << left << setw(15) << department << setw(20) << name << setw(15) << quantity << setw(1) << "$" 
				<< fixed << setprecision(2) << setw(14) << price << setw(1) << "$" << setw(14) << (price * quantity) << endl;
			totalValue += (price * quantity);
		}

	} while (!inFS.eof());

	cout << endl << "Value of of Items in " << type << " Supplies Inventory: $" << totalValue << endl << endl;

	inFS.close();
}

void OutputF()
{
	int quantity;
	double price;
	double totalValue;
	char department, tempDS;
	string name, type;

	ifstream inFS;
	ofstream outFS;
	outFS.open("Summary.txt");

	for (char i = 'E'; i <= 'O'; i += 10)
	{
		inFS.open("Office.txt");

		totalValue = 0;

		if (i == 'E')
		{
			type = "Electronics";
		}
		else if (i == 'O')
		{
			type = "Office";
		}

		outFS << type << " Supplies Inventory" << endl << endl;
		outFS << left << setw(15) << "Department" << setw(20) << "Name" << setw(15) << "Quanitiy" << setw(15) << "Price(each)" << setw(15) << "Price(total)" << endl;

		do
		{
			inFS >> department >> quantity >> name >> tempDS >> price;

			if (department == i && !inFS.eof())
			{
				outFS << left << setw(15) << department << setw(20) << name << setw(15) << quantity << setw(1) << "$"
					<< fixed << setprecision(2) << setw(14) << price << setw(1) << "$" << setw(14) << (price * quantity) << endl;
				totalValue += (price * quantity);
			}

		} while (!inFS.eof());

		outFS << endl << "Value of of Items in " << type << " Supplies Inventory: $" << totalValue << endl << endl;

		inFS.close();
	}

	outFS.close();
}