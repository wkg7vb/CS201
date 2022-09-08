#include "Lab08Utility.h"
using namespace std;

double FindTotal(vector<double> orig)
{
	int size = orig.size();
	double total = 0;

	for (int i = 0; i < size; ++i)
	{
		total += orig.at(i);
	}

	return (total);
}

double FindMean(vector<double> orig)
{
	int size = orig.size();
	double mean = FindTotal(orig) / size;

	return (mean);
}

double FindMedian(vector<double> orig)
{
	MySort(orig);

	int size = orig.size();
	double median;

	if (size %2 == 0)
	{
		median = (orig.at(size / 2) + orig.at(size / 2 + 1)) / 2;
	}
	else
	{
		median = orig.at(size / 2);
	}

	return (median);
}

void MySort(vector<double>& orig)
{
	int size = orig.size();
	double min = orig.at(0);
	double temp;
	int minK = 0;

	for (int i = 1; i < size; ++i)
	{
		min = orig.at(i);
		for (int k = i; k < size; ++k)
		{
			if (orig.at(k) < min)
			{
				min = orig.at(k);
				minK = k;
			}
		}
		temp = orig.at(i);
		orig.at(i) = min;
		orig.at(minK) = temp;
	}
}