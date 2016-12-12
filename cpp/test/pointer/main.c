#include <stdio.h>

void main()
{
	int intArr[10] = {0};
	short *p = (short *)intArr;
	
	for(int i = 0; i < 10; i++)
	{
		*p = i;
		p += 2;
	}

	int sum = 0;
	for(int j = 0; j < 10; j++)
	{
		sum += intArr[j];
	}

	printf("%d\n", sum);
}
