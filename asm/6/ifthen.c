 /* ifthen.c - A sample C if-then program */
#include <stdio.h>

int main()
{
	int a = 100;
	int b = 25;
	if (a > b)
	{
		printf("The higher value is %d", a);
	} else 
		printf("The higher value is %d", b);
	return 0;
}
