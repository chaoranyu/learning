#include <stdio.h>

void func1()
{
	int i, j;
	for (i = 0; i < 100000; i++)
		j += i;
}

void func2()
{
	int i, j;
	func1();
	for (i = 0; i < 200000; i++)
		j = i;
}

int main()
{
	int i;
	for (i = 0; i <100; i++)
		func1();

	for (i = 0; i <50000; i++)
		func2();

	return 0;
}
