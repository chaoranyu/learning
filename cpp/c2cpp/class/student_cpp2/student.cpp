#include <iostream>
#include <string.h>
#include "student.h"
using namespace std;

Student::Student(const char *name, int age, int score)
	:Person(name, age), score(score)
{
	cout << "create student" << endl;
}

Student::~Student()
{
	cout << "delete student" << endl;
}

void Student::display(void) const
{
	cout << "<<<<< display student infomation >>>>>" << endl
		 << " Name: " << name << endl << " Age: " << age << endl
		 << " score: " << score << endl;
}
