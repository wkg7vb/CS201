#include <iostream>
#include <string>
#include <vector>
#include "functions.h"
#include "queue.h"
#include "patient.h"
using namespace std;

int main()
{
	queue HClinic("Heart Clinic");
	queue LClinic("Lung Clinic");
	queue PSurgery("Plastic Surgery");

	bool main = true;

	while (main)
	{
		switch (mainMenu())
		{
			case '1':
			{
				departmentMenu(HClinic);
				break;
			}
			case '2':
			{
				departmentMenu(LClinic);
				break;
			}
			case '3':
			{
				departmentMenu(PSurgery);
				break;
			}
			case '4':
			{
				main = false;
				break;
			}
			default:
			{
				cout << "Invalid Input" << endl;
				break;
			}
		}
	}

	return 0;
}