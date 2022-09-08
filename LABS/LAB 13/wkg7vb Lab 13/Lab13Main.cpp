#include <string>
#include <iostream>
#include <fstream>
#include "templatefunc.h"
using namespace std;

int main()
{
	//declaring const variables for sizes, swap positions and searched values
	const int size = 100;
	const int swapPos1 = 10, swapPos2 = 20;
	const int iSearch1 = 1, iSearch2 = 5;
	const double dSearch1 = 4.62557, dSearch2 = 1.23456;
	const string sSearch1 = "Shoes", sSearch2 = "Pumpkin";

	//creating arrays and file streams
	int iArr[size];
	double dArr [size];
	string sArr[size];
	ifstream inFS;
	ofstream outFS;

	inFS.open("integers.txt");
	for (int i = 0; i < size; ++i)
	{
		inFS >> iArr[i];
	}
	inFS.close();

	inFS.open("doubles.txt");
	for (int i = 0; i < size; ++i)
	{
		inFS >> dArr[i];
	}
	inFS.close();

	inFS.open("strings.txt");
	for (int i = 0; i < size; ++i)
	{
		inFS >> sArr[i];
	}
	inFS.close();

	//excute functions with arrays of different data types
	outFS.open("output.txt");

	outFS << "Integers:" << endl
		<< "Swapping Data at indeces "<< swapPos1 << " and " << swapPos2 << "." << endl
		<< "Before: [" << swapPos1 << "] = " << iArr[swapPos1] << ", [" << swapPos2 << "] = " << iArr[swapPos2] << endl;
	mySwap(iArr, size, swapPos1, swapPos2);
	outFS << "After: [" << swapPos1 << "] = " << iArr[swapPos1] << ", [" << swapPos2 << "] = " << iArr[swapPos2] << endl
		<< "Minimum: " << myMin(iArr, size) << endl
		<< "Maximum: " << myMax(iArr, size) << endl
		<< "Value " << iSearch1 << " found at position " << mySearch(iArr, size, iSearch1) << endl
		<< "Value " << iSearch2 << " found at position " << mySearch(iArr, size, iSearch2) << endl << endl;

	outFS << "Doubles:" << endl
		<< "Swapping Data at indeces " << swapPos1 << " and " << swapPos2 << "." << endl
		<< "Before: [" << swapPos1 << "] = " << dArr[swapPos1] << ", [" << swapPos2 << "] = " <<dArr[swapPos2] << endl;
	mySwap(dArr, size, swapPos1, swapPos2);
	outFS << "After: [" << swapPos1 << "] = " << dArr[swapPos1] << ", [" << swapPos2 << "] = " << dArr[swapPos2] << endl
		<< "Minimum: " << myMin(dArr, size) << endl
		<< "Maximum: " << myMax(dArr, size) << endl
		<< "Value " << dSearch1 << " found at position " << mySearch(dArr, size, dSearch1) << endl
		<< "Value " << dSearch2 << " found at position " << mySearch(dArr, size, dSearch2) << endl << endl;

	outFS << "Strings:" << endl
		<< "Swapping Data at indeces " << swapPos1 << " and " << swapPos2 << "." << endl
		<< "Before: [" << swapPos1 << "] = " << sArr[swapPos1] << ", [" << swapPos2 << "] = " << sArr[swapPos2] << endl;
	mySwap(sArr, size, swapPos1, swapPos2);
	outFS << "After: [" << swapPos1 << "] = " << sArr[swapPos1] << ", [" << swapPos2 << "] = " << sArr[swapPos2] << endl
		<< "Minimum: " << myMin(sArr, size) << endl
		<< "Maximum: " << myMax(sArr, size) << endl
		<< "Value " << sSearch1 << " found at position " << mySearch(sArr, size, sSearch1) << endl
		<< "Value " << sSearch2 << " found at position " << mySearch(sArr, size, sSearch2);

	outFS.close();
	return 0;
}