#include "student.h"

int main(void)
{
	HSTUDENT student = student_create("XiaoMing", 12, 99);
	display(student);
	student_delete(student);

	HPERSON person = person_create("XiaoMing", 12);
	display(person);
	person_delete(person);

	return 0;
}
