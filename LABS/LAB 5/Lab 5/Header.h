#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;

double GetMiles();
double GetGallons();
double GetMPG(vector <double> miles, vector <double> gallons);
bool again();