#include <stdio.h>

void main()
{
	int array[10] = {105, 235, 61, 315, 134, 221, 53, 145, 117, 5};
	int temp;
	for (int out = 9; out > 0; out--)
	{
		for (int in = 0; in < out; in++)
		{
			if (array[in] > array[in+1])
			{
				temp = array[in];
				array[in] = array[in+1];
				array[in+1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");
}
