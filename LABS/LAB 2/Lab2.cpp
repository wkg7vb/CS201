#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<double> dailyTotals;
	double dailyTotal, threeDayTotal = 0, ticketAmount;
	const double priceC = 10.95, priceA = 19.99, priceS = 18.99, priceVIP = 7.99;
	char ticketType;
	bool done4day, validInput;

	for (int i = 1; i <= 3; i++)
	{
		dailyTotals.resize(4);
		dailyTotals = {0, 0, 0, 0};
		done4day = 0;

		cout << "Day " << i << ":" << endl << endl;
		
		while (!done4day)
		{
			cout << "Input type of ticket: (C)hild, (A)dult, (S)enior, (V)IP, or (Q)uit to end the day." << endl;
			cin >> ticketType;
			ticketType = toupper(ticketType);
			do
			{
				validInput = 0;
				if (ticketType != 'C' && ticketType != 'A' && ticketType != 'S' && ticketType != 'V' && ticketType != 'Q')
				{
					cout << "Invalid input, please enter C, A, S or V." << endl;
					cin >> ticketType;
				}
				else
				{
					validInput = 1;
				}
			} while (!validInput);
			
			switch (ticketType)
			{
				case 'C':
				{
					cout << "Input amount of Child tickets sold." << endl;
					cin >> ticketAmount;
					dailyTotals[0] += ticketAmount;
					break;
				}
				case 'A':
				{
					cout << "Input amount of Adult tickets sold." << endl;
					cin >> ticketAmount;
					dailyTotals[1] += ticketAmount;
					break;
				}
				case 'S':
				{
					cout << "Input amount of Senior tickets sold." << endl;
					cin >> ticketAmount;
					dailyTotals[2] += ticketAmount;
					break;
				}
				case 'V':
				{
					cout << "Input amount of VIP tickets sold." << endl;
					cin >> ticketAmount;
					dailyTotals[3] += ticketAmount;
					break;
				}
				case 'Q':
				{
					done4day = 1;
					break;
				}
			}

		}

		dailyTotal = (dailyTotals[0] * priceC) + (dailyTotals[1] * priceA) + (dailyTotals[2] * priceS) + (dailyTotals[3] * priceVIP);
		threeDayTotal += dailyTotal;

		cout << endl;
		cout << "Day " << i << " Sales:" << endl << endl;
		cout << dailyTotals[0] << " child tickets @ " << priceC << ": " << dailyTotals[0] * priceC << endl;
		cout << dailyTotals[1] << " adult tickets @ " << priceA << ": " << dailyTotals[1] * priceA << endl;
		cout << dailyTotals[2] << " senior tickets @ " << priceS << ": " << dailyTotals[2] * priceS << endl;
		cout << dailyTotals[3] << " VIP tickets @ " << priceVIP << ": " << dailyTotals[3] * priceVIP << endl << endl;
		cout << "Day " << i << " Total: " << dailyTotal << endl << endl;
	}

	cout << "The total for all three days is " << threeDayTotal << endl;

	return (0);
}