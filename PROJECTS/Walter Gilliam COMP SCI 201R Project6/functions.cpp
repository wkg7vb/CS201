#include "functions.h"
using namespace std;

char mainMenu()
{
	char input;

	cout << endl << "Welcome to 201 Hospital" << endl
		<< "1: Heart Clinic" << endl
		<< "2: Lung Clinic" << endl
		<< "3: Plastic Surgery" << endl
		<< "4: Exit" << endl
		<< "Please enter your choice: ";

	cin >> input;

	return input;
}

void departmentMenu(queue &dep)
{
	char input;

	cout << endl << "Welcome to department: " << dep.getDName() << endl
		<< "1: Add patient" << endl
		<< "2: Add critically ill patient" << endl
		<< "3. Take patient for operation" << endl
		<< "4: Cancel patient" << endl
		<< "5: List queue of patients" << endl
		<< "6: Change departments or Exit" << endl
		<< "Please enter your choice: ";

	cin >> input;
	
	switch (input)
	{
		case '1':
		{
			addPatient(dep);
			departmentMenu(dep);
			break;
		}
		case '2':
		{
			addCPatient(dep);
			departmentMenu(dep);
			break;
		}
		case '3':
		{
			takePatient(dep);
			departmentMenu(dep);
			break;
		}
		case '4':
		{
			cancelPatient(dep);
			departmentMenu(dep);
			break;
		}
		case '5':
		{
			listPatients(dep);
			departmentMenu(dep);
			break;
		}
		case '6':
		{
			break;
		}
		default:
		{
			cout << "Invalid Input" << endl;
			departmentMenu(dep);
			break;
		}
	}
}

void addPatient(queue &dep)
{
	patient temp = getPatientInfo();
	dep.push_back(temp);
}

void addCPatient(queue &dep)
{
	patient temp = getPatientInfo();
	dep.push_front(temp);
}

void takePatient(queue &dep)
{
	cout << "First patient in line has been removed from the queue" << endl;
	dep.pop();
}

void cancelPatient(queue &dep)
{
	patient temp = getPatientInfo();
	dep.erase(temp);
}

void listPatients(queue &dep)
{
	dep.printAll();
}

patient getPatientInfo()
{
	string fname, lname;
	int ssNum;
	cout << endl << "Input Patient Information" << endl;
	cout << "First Name: ";
	cin >> fname;
	cout << "Last Name: ";
	cin >> lname;
	cout << "Social Security Number: ";
	cin >> ssNum;

	return (patient(fname, lname, ssNum));
}