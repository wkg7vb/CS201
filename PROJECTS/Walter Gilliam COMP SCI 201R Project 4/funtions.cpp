#include "functions.h"
using namespace std;

void mySort(vector<Student>& roster)
{
	int size = roster.size();
	int maxI;
	Student Max;
	
	for (int k = 0; k < size - 1; ++k)
	{
		Max = roster.at(k);
		maxI = k;
		for (int i = k + 1; i < size; ++i)
		{
			if (roster.at(i).CourseAverage() > Max.CourseAverage())
			{
				Max = roster.at(i);
				maxI = i;
			}
			else if (roster.at(i).CourseAverage() == Max.CourseAverage())
			{
				if (roster.at(i).GetFirstName() < Max.GetFirstName())
				{
					Max = roster.at(i);
					maxI = i;
				}
			}
		}
		swap(roster, k, maxI);
	}
}

void swap(vector<Student>& roster, int index1, int index2)
{
	Student temp;
	temp = roster.at(index1);
	roster.at(index1) = roster.at(index2);
	roster.at(index2) = temp;
}