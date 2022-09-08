#include "Student.h"
#include "functions.h"
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	//declare variables
	int size;
	vector <Student> roster;
	Student temp;
	ifstream inFS;
	ofstream outFS;

	//open input file stream and find roster size
	inFS.open("Program4Data.txt");
	inFS >> size;

	//read data from Program4Data.txt into vector
	for (int i = 0; i < (size); ++i)
	{
		temp.AquireData(inFS);
		roster.push_back(temp);
	}

	//close input file stream
	inFS.close();

	//sort the data by course average (high to low)
	mySort(roster);

	//open output file stream
	outFS.open("output.txt");

	for (int i = 0; i < (size); ++i)
	{
		//ouput name, grade and letter to console
		cout << left << setw(20) << roster.at(i).GetFirstName() << setw(20) << roster.at(i).GetLastName()
			<< setw(10) << fixed << setprecision(1) << roster.at(i).CourseAverage() 
			<< setw(1) << roster.at(i).LetterGrade() << endl;

		//output name and individual grades to output.txt
		roster.at(i).PrintData(outFS);
	}

	cout << "More information found in output.txt" << endl;

	//close output file stream
	outFS.close();

	return (0);
}