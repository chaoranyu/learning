#include <stdio.h>

void shellsort(int v[], int n);

int main()
{
	int v[10] = {33, 59, 22, 1, 6, 99, 2, 9, 55, 76};

	for (int i = 0; i < 10; i++)
		printf("%2d  ", v[i]);
	printf("\n");
	
	shellsort(v, 10);
	for (int i = 0; i < 10; i++)
		printf("%2d  ", v[i]);
	printf("\n");

	return 0;
}

void shellsort(int v[], int n)
{
	int i, j, gap, temp;

	for (gap = n/2; gap > 0; gap /= 2)
		for (i = gap; i < n; i++)
			if ( v[i-gap]>v[i] )
			{
				temp = v[i-gap];
				v[i-gap] = v[i];
				v[i] = temp;			
			}
}
