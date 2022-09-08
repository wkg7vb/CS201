#include "Lab08Utility.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	vector<double> DVD;
	vector<double> TV;
	vector<double> MUSIC;
	string type;
	double amount;
	bool loop = true;

	ifstream inFS;
	ofstream outFS;

	inFS.open("input.txt");
	while(loop)
	{
		inFS >> type >> amount;

		if (type == "DVD")
		{
			DVD.push_back(amount);
		}
		else if (type == "TV")
		{
			TV.push_back(amount);
		}
		else if (type == "MUSIC")
		{
			MUSIC.push_back(amount);
		}
		
		if (inFS.eof())
		{
			loop = false;
		}

	}
	inFS.close();

	cout << left << fixed << setprecision(2); 
	cout << setw(8) << "TYPE" << setw(8) << "TOTAL" << setw(8) << "MEAN" << setw(8) << "MEDIAN" << endl;
	cout << setw(8) << "DVD" << setw(8) << FindTotal(DVD) << setw(8) << FindMean(DVD) << setw(8) << FindMedian(DVD) << endl;
	cout << setw(8) << "TV" << setw(8) << FindTotal(TV) << setw(8) << FindMean(TV) << setw(8) << FindMedian(TV) << endl;
	cout << setw(8) << "MUSIC" << setw(8) << FindTotal(MUSIC) << setw(8) << FindMean(MUSIC) << setw(8) << FindMedian(MUSIC) << endl;

	outFS.open("output.txt");
	outFS << left << fixed << setprecision(2);
	outFS << setw(8) << "TYPE" << setw(8) << "TOTAL" << setw(8) << "MEAN" << setw(8) << "MEDIAN" << endl;
	outFS << setw(8) << "DVD" << setw(8) << FindTotal(DVD) << setw(8) << FindMean(DVD) << setw(8) << FindMedian(DVD) << endl;
	outFS << setw(8) << "TV" << setw(8) << FindTotal(TV) << setw(8) << FindMean(TV) << setw(8) << FindMedian(TV) << endl;
	outFS << setw(8) << "MUSIC" << setw(8) << FindTotal(MUSIC) << setw(8) << FindMean(MUSIC) << setw(8) << FindMedian(MUSIC);
	outFS.close();

	return(0);
}