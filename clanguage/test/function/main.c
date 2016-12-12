#include <stdio.h>

int print(int x)
{
	printf("wahaha, %d\n", x);
	return 3;
}

void main()
{
	int (*FuncType1)(int x);
	FuncType1 = print;

	int num = FuncType1(8);
	printf("num is %d\n", num);

	typedef int (*FuncType2)(int x);
	FuncType1 func1 = print;

	int num2 = func1(8);
	printf("num is %d\n", num2);
}
