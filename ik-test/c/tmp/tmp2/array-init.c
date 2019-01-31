#include <stdio.h>

#define ARRAY_SIZE	100

int main()
{
	int a[ARRAY_SIZE] = { 0 };
	//int a[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%10d  ", a[i]);

		if (i % 10 == 9)
			printf("\n");
	}

	printf("\n");

	return 0;
}
