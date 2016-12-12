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
			for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
			{
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;			
			}
}
