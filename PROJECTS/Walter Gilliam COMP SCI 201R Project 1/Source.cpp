//Walter Gilliam	COMP SCI 201R	Program 1	9/2/21	Due 9/12/21

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	//declaration of variables and seeding rand()
	int die1, die2;
	int rollCount = 0;
	char playAgain;
	srand(time(0));

	//massive do loop to keep playing if the user desires
	do
	{
		//rolling the first die
		die1 = (rand() % 6) + 1;

		cout << "The first die rolled a " << die1 << endl;

		//rolling the second die until it matches the first die
		do
		{
			die2 = (rand() % 6) + 1;
			cout << "Round " << rollCount + 1 << ": ";
			cout << "The second die rolled a " << die2 << endl;
			rollCount++;
		} while (die1 != die2);

		//outputs roll count and declares win/loss
		cout << "The dice matched in " << rollCount << " rolls." << endl;

		if (rollCount <= 3)
		{
			cout << "Computer Wins!" << endl;
		}
		else
		{
			cout << "Computer Loses!" << endl;
		}

		//asks to play again
		cout << "Would you like to play again? Y/N" << endl;

		//accepts user input in both capital and lowercase form and continues program accordinglly
		do
		{
			cin >> playAgain;

			switch (playAgain)
			{
				case 'Y':
					break;

				case 'y':
					rollCount = 0;
					playAgain = 'Y';
					break;

				case 'N':
					break;

				case 'n':
					playAgain = 'N';
					break;

				default:
					cout << endl << "Invalid input, please input 'Y' or 'N'." << endl;
					break;
			}
		} while (playAgain != 'Y' && playAgain != 'N');

		cout << endl;

	} while (playAgain == 'Y');

	//wishing the user a good day when they decide to stop playing
	cout << "Have a great day!" << endl;
	
	return 0;
}