#include "student.h"

int main(void)
{
	Student *student = new Student("XiaoMing", 12, 99);
	student->display();

	Person *person = student;
	person->display();

	delete student;

	person = new Person("XiaoHua", 11);
	person->display();
	delete person;

	return 0;
}
