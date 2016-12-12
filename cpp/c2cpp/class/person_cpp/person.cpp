#include <iostream>
#include <string.h>
#include "person.h"
using namespace std;

Person::Person(const char *name, int age)
	:name(NULL), age(age)
{
	cout << "create person" << endl;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name); 
}

Person::~Person()
{
	cout << "delete person" << endl;
	delete []name;
}

void Person::display() const
{
	cout << "<<<<< display person infomation >>>>>" << endl
		 << " Name: " << this->name << endl << " Age: " << this->age << endl;
}
