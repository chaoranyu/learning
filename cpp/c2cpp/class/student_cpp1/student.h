#include "person.h"

class Student: public Person
{
public:
	Student(const char *name, int age, int score);
	~Student();
	void display(void) const;
private:
	int score;
};
