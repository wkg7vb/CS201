#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

//Walter Gilliam	Project 2

//Function Declarations

//Checks if player is in start or will go over 30. Returns True if the move is valid, returns false if the move is invalid.
bool CheckValid(int positions[], int player, int card);

//Draws a card for the player, values are 1-12. Updates players scores after calling CheckValid.
void DrawCard(int positions[], int player);

//Called if the player draws a 4.
void Sorry(int positions[], int player);

//Checks each player position for a winner. If a winner is found user is asked if they want to play again.
void CheckWinner(int positions[], bool& again, bool& winner);

//Validates bool inputs to be either 1 or 0
bool BoolChecker(char& needsChecked);

int main()
{	//Declare variables and seed rand()
	int playerPositions[2];
	bool playAgain, winnerFound;
	srand(time(NULL));

	do
	{
		playAgain = 0;
		winnerFound = 0;
		playerPositions[0] = 0;
		playerPositions[1] = 0;

		cout << "Lets Play Sorry!" << endl;
		cout << "This is a game for 2 players." << endl;
		cout << "Press enter to start your turn." << endl << endl;

		while(!winnerFound)
		{
			for (int i = 0; i < 2; ++i)
			{
				cin.get();
				DrawCard(playerPositions, i);
				cout << "Player " << i + 1 << " is on square " << playerPositions[i] << "." << endl;
				CheckWinner(playerPositions, playAgain, winnerFound);
				if (winnerFound){break;}
				cout << endl;
			}
		}
		
	} while (playAgain);

	return (0);
}

//Function Definitions

bool CheckValid(int positions[], int player, int card)
{
	if (positions[player] == 0 && (card == 1 || card == 2))
	{
		cout << "Lucky you, you get to leave Home and move " << card << " spaces." << endl;
		return 1;
	}
	else if (positions[player] == 0 && (card != 1 && card != 2))
	{
		cout << "Unlucky, you can't leave Home yet." << endl;
		return 0;
	}
	else if (card == 4)
	{
		Sorry(positions, player);
		return 0;
	}
	else if (positions[player] + card > 30)
	{
		cout << "You can't land exactly on the Goal, better luck next time." << endl;
		return 0;
	}
	else
	{
		cout << "Move forward " << card << " spaces." << endl;
		return 1;
	}
}

void DrawCard(int positions[], int player)
{
	int card;

	card = (rand() % 12) + 1;

	cout << "Player "<< player + 1 << " is on square " << positions[player] << " and drew a " << card << endl;

	if (CheckValid(positions, player, card))
	{
		positions[player] += card;
	}
}

void Sorry(int positions[], int player)
{
	char choice;
	bool temp;

	cout << "You drew a 4" << endl
		<< "You can say, \"SORRY\" (take your opponents place and send them Home), or move forward 4" << endl
		<< "Enter 1 for SORRY or 0 to move FORWARD 4 spaces." << endl;
	cin >> choice;
	cin.get();
	temp = BoolChecker(choice);

	if (temp)
	{
		cout << "SORRY!" << endl;
		if (player == 0)
		{
			positions[0] = positions[1];
			positions[1] = 0;
		}
		else if (player == 1)
		{
			positions[1] = positions[0];
			positions[0] = 0;
		}
	}
	else if (positions[player] + 4 > 30)
	{
		cout << "You can't land on the Goal exactly, better luck next time." << endl;
	}
	else
	{
		cout << "Move forward 4" << endl;
		positions[player] += 4;
	}
}

void CheckWinner(int positions[], bool& again, bool& winner)
{
	char temp;

	for (int i = 0; i < 2; ++i)
	{
		if (positions[i] == 30)
		{
			cout << endl;
			cout << "Player " << i + 1 << " wins!" << endl;
			cout << "Would you like to play again?" << endl;
			cout << "Enter 1 for yes or 0 for no." << endl;
			cin >> temp;
			cin.get();
			again = BoolChecker(temp);
			winner = "true";
			cout << endl;
		}
	}
}

bool BoolChecker(char& needsChecked)
{
	char temp = needsChecked;
	while (temp < '0' || temp > '1')
	{
		cout << endl << "Invalid input, please enter 1 or 0" << endl;
		cin >> temp;
		cin.get();
	}
	return (temp - 48);
}