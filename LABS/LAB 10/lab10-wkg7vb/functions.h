#pragma once

#include "Employee.h"
#include <vector>

//returns index of employee with id number, given an id number and the roster.
int find(const int& idNum, vector<Employee> roster);