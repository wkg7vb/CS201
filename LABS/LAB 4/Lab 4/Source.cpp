#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct point
{
	double x;
	double y;
	double z;
};

double calcDistance(point first, point second);		//will calculate the distance between two points
void outputPoint(point interest);					//will cout a single point for console debugging

int main()
{
	double distance;
	point first, second;
	vector<point> points;

	ifstream inFS;
	ofstream outFS;

	inFS.open("input.txt");
	//inFS.open("input_test.txt"); //switch between test and actual files faster
	outFS.open("output.txt");

	while (!inFS.eof())
	{
		//input from file
		inFS >> first.x >> first.y >> first.z >> second.x >> second.y >> second.z;
		distance = calcDistance(first, second);

		//output to file
		outFS << distance << endl;

		//output to console for debugging
		outputPoint(first);
		outputPoint(second);
		cout << distance << endl;

		//add points to vector
		points.push_back(first);
		points.push_back(second);
	}

	inFS.close();
	outFS.close();

	return 0;
}

double calcDistance(point first, point second)
{
	return sqrt(pow((first.x - second.x), 2) + pow((first.y - second.y), 2) + pow((first.z - second.z), 2));
}

void outputPoint(point interest)
{
	cout << interest.x << " " << interest.y << " " << interest.z << endl;
}