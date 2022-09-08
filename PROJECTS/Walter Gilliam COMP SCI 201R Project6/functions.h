#pragma once
#include <iostream>
#include <vector>
#include "queue.h"
#include "patient.h"
using namespace std;

char mainMenu();
void departmentMenu(queue &dep);
void addPatient(queue &dep);
void addCPatient(queue &dep);
void takePatient(queue &dep);
void cancelPatient(queue &dep);
void listPatients(queue &dep);
patient getPatientInfo();