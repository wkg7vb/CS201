#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class StudentInfo {
private:
	string name;
	StudentInfo* nextStudentPtr;
public:
	StudentInfo(string value, StudentInfo* nextItem);
	string getName() { return name; };
	StudentInfo* getNextStudent() { return nextStudentPtr; };
	void setNextStudent(StudentInfo* item);
	void deleteNext();
	void insertAfter(StudentInfo* item);
	friend bool operator== (const StudentInfo &s1, const StudentInfo &s2);
	friend bool operator< (const StudentInfo &s1, const StudentInfo &s2);

};

StudentInfo::StudentInfo(string value, StudentInfo* nextItem = nullptr) {
	this->name = value;
	this->nextStudentPtr = nextItem;
}

bool operator== (const StudentInfo &s1, const StudentInfo &s2) {
	return (s1.name == s2.name);
}

bool operator< (const StudentInfo &s1, const StudentInfo &s2) {
	return (s1.name < s2.name);
}

void StudentInfo::setNextStudent(StudentInfo* item) {
	this->nextStudentPtr = item;
}

void StudentInfo::deleteNext() {
	StudentInfo* temp = this->getNextStudent()->getNextStudent();
	delete this->getNextStudent();
	this->nextStudentPtr = temp;
}

void StudentInfo::insertAfter(StudentInfo* item) {
	StudentInfo* temp = this->getNextStudent();
	this->nextStudentPtr = item;
	item->setNextStudent(temp);
}


int main() {

	
	cout << "welcome" << endl;

	return 0;
}