#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
	public:
		Student();
		bool AquireData(istream& inSS);
		bool PrintData(ostream& outSS) const;
		string GetFirstName() const { return (firstName); };
		string GetLastName() const { return (lastName); };
		float CourseAverage() const;
		bool DisplayCourseAverage(ostream& outSS);
		string LetterGrade();

	private:
		string firstName;
		string lastName;
		float quiz1;
		float quiz2;
		float quiz3;
		float quiz4;
		float exam1;
		float exam2;
		float finalProject;
};

