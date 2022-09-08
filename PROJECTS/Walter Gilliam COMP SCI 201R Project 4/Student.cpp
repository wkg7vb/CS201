#include "Student.h"
using namespace std;

Student::Student()
{
	firstName = "";
	lastName = "";
	quiz1 = 0;
	quiz2 = 0;
	quiz3 = 0;
	quiz4 = 0;
	exam1 = 0;
	exam2 = 0;
	finalProject = 0;
}

bool Student::AquireData(istream& inSS)
{
	try
	{
		inSS >> firstName >> lastName >> quiz1 >> quiz2 >> quiz3 >> quiz4 >> exam1 >> exam2 >> finalProject;
	}
	catch (...)
	{
		return (false);
	}
}

bool Student::PrintData(ostream& outSS) const
{
	try
	{
		outSS << left << setw(20) << firstName << setw(20) << lastName << 
			right << setw(4) << setw(4) << quiz1 << setw(4) << quiz2 << setw(4) << quiz3 << setw(4) << quiz4 <<
			setw(5) << exam1 << setw(5) << exam2 << setw(5) << finalProject << endl;
		return (true);
	}
	catch(...)
	{
		return (false);
	}
}

float Student::CourseAverage() const
{
	float quizAvgWei = 35 * (((quiz1 + quiz2 + quiz3 + quiz4) / 4) / 10) ;
	float examAvgWei = 35 * (((exam1 + exam2) / 2) / 100);
	float finalWei = 30 * (finalProject / 100);
	float average = quizAvgWei + examAvgWei + finalWei;
	return (average);
}

bool Student::DisplayCourseAverage(ostream& outSS)
{
	try
	{
		outSS << fixed << setprecision(1) << CourseAverage();
		return (true);
	}
	catch (...)
	{
		return (false);
	}
}

string Student::LetterGrade()
{
	float avg = CourseAverage();
	if (avg >= 93)		{ return ("A"); }
	else if (avg >= 90) { return ("A-"); }
	else if (avg >= 87) { return ("B+"); }
	else if (avg >= 83) { return ("B"); }
	else if (avg >= 80) { return ("B-"); }
	else if (avg >= 77) { return ("C+"); }
	else if (avg >= 73) { return ("C"); }
	else if (avg >= 70) { return ("C-"); }
	else if (avg >= 67) { return ("D+"); }
	else if (avg >= 63) { return ("D"); }
	else if (avg >= 60) { return ("D-"); }
	else if (avg >= 0)	{ return ("F"); }
}